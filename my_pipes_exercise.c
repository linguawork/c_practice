#include "minishell.h"

char **pipe_next_cmd_recorder(t_job *job)
{
    char **cmd_array;
    int len;
    char **args;
    char *cmd;

    cmd = job->pipe_next->redir->command;
    args = job->pipe_next->redir->args;
    int i = 1;
    int j = 0;
    if (args == NULL)// если аргумент всего 1 (то это сама команда) то пишем его в массив env и 1 ячейку резерв для терминатора
    {
        cmd_array = (char **) malloc(sizeof(char *) * (1 + 1));
        cmd_array[0] = cmd;
    }
    else// если аргументов не один
    {
        len = how_many_lines((char **) args);// считаем кол-во аргументов
        cmd_array = (char **) malloc(sizeof(char *) * (len + 1+1)); // выделяем память + 1 для ноля и +1 для команды
        cmd_array[0] = cmd;
        while (args[j] != NULL) // запись из оригинала в замолоченный двумерный массив с размером рядов оригинала после записи команды
        {
            cmd_array[i] = args[j];// лучше записывать через индекс// i = 1 так как в ноль записана команда, j = 0
            j++;
            i++;
        }
    }
    cmd_array[i]=NULL;// в конце добав терминатор
    return(cmd_array);
}

char ***pipe_cmd_args_recorder(t_main *main) // запись команд и их аргументов в 2м массив
{
    int i;
    int c_num;


    char ***cmds;
    int p_num;
    t_job *job;

    c_num= main->job->num_commands;
    job = main->job;
//    c_num = 4; // this is for test
//    p_num =  main->job->num_pipes;

//    c_num = how_many_lines(main->job); // подсчет комманд
//    c_num = 2;
    cmds = (char ***) malloc(sizeof(char *) * (c_num + 1));

    p_num = c_num - 1;
    i = 0;
    if (p_num == 1)
    {
        cmds[i] = cmd_args_to_argv_recorder(main);
        cmds[++i] = pipe_next_cmd_recorder(job);
        cmds[++i] = NULL;
        return(cmds);
    }

    if (p_num > 1)
    {
        cmds[i] = cmd_args_to_argv_recorder_p(job);
        cmds[++i] = pipe_next_cmd_recorder(job);
        while (job->job_next)
        {
            job = job->job_next;// трансформация структуры
            cmds[++i] = cmd_args_to_argv_recorder_p(job); // функция для main->job->pipe

            if (job->pipe_next)
                cmds[++i] = pipe_next_cmd_recorder(job); // функция для main->job->pipe_next
        }
        cmds[++i] = NULL;
    }
    return(cmds);
}

void connect_stdio_to_pipes(int prev_fds[], int next_fds[])
{
    if (prev_fds[0] >= 0) // если есть что-то в нулевом фд (вход) или ноль ()
    {
        dup2(prev_fds[0], 0); // дублируем нулевой в ноль (запись в файл) // вливание в трубу
        close(prev_fds[0]);
        close(prev_fds[1]);
    }
    if (next_fds[1] >= 0)// след 1 фд на выход имеет что-то
    {
        dup2(next_fds[1], 1); // дублируем 1 в 1 (письмо из файла = выход) выливание из трубы
        close(next_fds[1]);
        close(next_fds[0]);
    }
}

void execute_pipes (t_main *main)
{
    int c_num;
    char ***commands;
    int prev_pipe_fds[2]; // объявляем массив предыдущ файловых дескрипторов
    int next_pipe_fds[2];
    char **cmd;
//    int fork_res;
//    int status;

    commands = pipe_cmd_args_recorder(main);
//    char **cmd = &*commands[i]; // по адресу передаем значение в разыменовании 3мерного в 2хмерный // test
//    length = how_many_lines(*commands); // кол-во комманд
    c_num = main->job->num_commands;
//    c_num = 4;

    int i = 0; // итератор
    next_pipe_fds[0] = -1; // инициализация  значения следующих файловых дескрипторов нулевого элемента
    next_pipe_fds[1] = -1;
    while (i < c_num) // пока не прошлись по всем командам
    {
        prev_pipe_fds[0] = next_pipe_fds[0]; // предыдущ нулевой присваивает значение след нулевого
        prev_pipe_fds[1] = next_pipe_fds[1];
        if (i != c_num - 1) // если кол-во команд не равно количеству команд-1 (те кол-ву пайпов)
            pipe(next_pipe_fds);// создаем каналы (трубы для следующих команд)
        else // иначе если команды равны пайпам
        {
            next_pipe_fds[0] = -1; // инициализируем на -1
            next_pipe_fds[1] = -1;
        }
//        status = 0;
//        cmd = &*commands[i];
//        fork_res = fork();
        if (fork() == 0) // в дочери
        {
            connect_stdio_to_pipes(prev_pipe_fds, next_pipe_fds); // соединяем предыд в следующие
            cmd = &*commands[i]; // берем указатель по адресу из элемента трехмерного и передаем указатель на двумерный массив для подачи в execve
            execve(cmd[0], cmd, NULL);// исполняем в дочери
            //exit(127);// не нужен exit, так как  дочерний процесс сам себя зачищает
//            process_builtins_and_divide_externals(main);
//            process_exe(main);
        }
        close(prev_pipe_fds[0]); // закрываем вход предыдущ
        close(prev_pipe_fds[1]); // закрываем вход предыдущ


//        waitpid(fork_res, &status, 0);
//        main->exit = WEXITSTATUS(status);

        // for testing
//        ft_putstr_fd("status number is ", 1);
//        ft_putnbr_fd(status, 1);
//        write(1, "\n", 1);
//        ft_putstr_fd("Wexitstatus(status) is ", 1);
//        ft_putnbr_fd (WEXITSTATUS(status), 1); // запись кода выхода 1
//        write(1, "\n", 1);
//        ft_putstr_fd("main_>exit is ", 1);
//        ft_putnbr_fd (main->exit, 1);
//        write(1, "\n", 1);
//        ft_putstr_fd("parent id is ", 1); // если использовать printf то печатает после завершения программы
//        ft_putnbr_fd (fork_res, 1);// ID родителя
//        write(1, "\n", 1);
        i++;

    }
    wait(NULL); // один wait может ждать несколько процессов // без pid
}