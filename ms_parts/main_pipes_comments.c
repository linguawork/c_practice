#include <unistd.h> // for pipe
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
// shell pipe
// cmd1 -> pipe -> cmd2 -> pipe -> cmd3
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

int main(int argc, char **argv, char **envp)
{
    char *cmd1[] = { "/bin/echo", "12345", NULL }; // объявление путей комманд (обязательно должны быть пути) 
    char *cmd2[] = { "/usr/bin/sed", "s/123/ddd/p", NULL };
    char *cmd3[] = { "/usr/bin/sed", "s/ddd/aaa/p", NULL };
    char *cmd4[] = { "/usr/bin/sed", "s/aaa/000/p", NULL };
    char **cmds[5]; // создание 2мерного массива команд
    cmds[0] = cmd1; // присвоение команд в 2мерный массив
    cmds[1] = cmd2;
    cmds[2] = cmd3;
    cmds[3] = cmd4;
    cmds[4] = NULL;
    int i = 0; // итератор
    int cmds_count = 2; // число команд
    int prev_pipe_fds[2]; // объявляем массив предыдущ файловых дескрипторов
    int next_pipe_fds[2];
    next_pipe_fds[0] = -1; // инициализация  значения следующих файловых дескрипторов нулевого элемента
    next_pipe_fds[1] = -1;
    while (i < cmds_count) // пока не прошлись по всем командам
    {
        prev_pipe_fds[0] = next_pipe_fds[0]; // предыдущ нулевой присваивает значение след нулевого
        prev_pipe_fds[1] = next_pipe_fds[1];
        if (i != cmds_count - 1) // если кол-во команд не равно количеству команд-1 (те кол-ву пайпов)
            pipe(next_pipe_fds);// создаем каналы (трубы для следующих команд)
        else // иначе если команды равны пайпам
        {
            next_pipe_fds[0] = -1; // инициализируем на -1
            next_pipe_fds[1] = -1;
        }
        if (fork() == 0) // в дочери
        {
            connect_stdio_to_pipes(prev_pipe_fds, next_pipe_fds); // соединяем предыд в следующие
            char **cmd = cmds[i]; // команду пишем в двумерный для подачи в execve
            execve(cmd[0], cmd, NULL);// исполняем в дочери
            //exit(127);// не нужен exit, так как  дочерний процесс сам себя зачищает
        }
        close(prev_pipe_fds[0]); // закрываем вход предыдущ
        close(prev_pipe_fds[1]); // закрываем вход предыдущ
        i++;
    }
    wait(NULL); // один wait не может ждать несколько процессов // без pid (ЛУЧШЕ В ЦИКЛЕ)
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return (0);
}
