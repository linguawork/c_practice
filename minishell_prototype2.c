#include "minishell.h"

int count_args(char **args)
{
    int i;

    i = 0;
    while(args[i])
        i++;
    return(i);
}

int how_many_lines(char **a)
{
    int i;
    char **env;

    i = 0;
    env = a;
    while(env[i] != NULL)
    {
        i++;
    }
    return(i);
}

int echo(t_main *main)
{
	char *command;
	char **args;
	// char *flags;

	command = main->job->pipe->redir->command;
    args = main->job->pipe->redir->args;
	// flags = main->job->pipe->redir->flags;
	if (command != '\0')
	{
	    if (command && !args)
            ft_putchar_fd('\n', 1);
	    // if (command && flags && !(args))
        // {
        //     if (command && ft_strcmp(flags, "-n") == 0)
        //         return(0);
		// 	else
        //     {
        //         write(1, flags, ft_strlen(flags));
        //         write(1, "\n", 1);
        //     }
        // }
        // if (command && !flags && args)
        // {
		// 	// if (command && ft_strcmp(*args, "-n") == 0)
        //     //     return(0);
		// 	else
        //     {
        //         write(1, *args, ft_strlen(*args));
        //         write(1, "\n", 1);
        //     }
		// 	ft_putstr_fd(*args, 1);
		// 	while (*++args)// skip 1 and then go into cycle
		// 	{

		// 		ft_putchar_fd(' ', 1);
		// 		ft_putstr_fd(*args, 1);
		// 	}
		// 	ft_putchar_fd('\n', 1);

        // }
		if (command && args)
        {
			while (*args != NULL && (ft_strcmp(*args, "-n") == 0))
				args++;	
			if (*args == NULL)
				return(0);
			if (command && !(ft_strcmp(*args, "-n") == 0))
			{
				if (*(args - 1) != NULL && ft_strcmp(*(args - 1), "-n") == 0 && !(ft_strcmp(*args, "-n") == 0))
				{
					write(1, *args, ft_strlen(*args));
					while (*++args != NULL)
					{
						ft_putchar_fd(' ', 1);
						write(1, *args, ft_strlen(*args));				
					}
				}	
				if (*(args - 1) == NULL && !(ft_strcmp(*args, "-n") == 0))
				{
					while (*args != NULL)
					{
						ft_putstr_fd(*args, 1);
						ft_putchar_fd(' ', 1);
						args++;				
					}
					ft_putchar_fd('\n', 1);
				}
            }
			
        }
	}
	return(0);
}

char *ft_getenv(t_main *main, char *name)
{
	char **env;
	int len;
	int i;
	char *name_or_value;

	env = main->my_env;
	i = 0;
	while (env[i] != NULL)
	{
		if(ft_strchr(env[i], '=')) 
		{
			len= char_count(env[i]); // замер до равно (длина строки до =)
			name_or_value = ft_substr(env[i], 0, len); // отрезать до равно получается en без равно
			if(ft_strcmp(name_or_value, name) != 0)// освобождаем если не нашли
					free(name_or_value);
			if(ft_strcmp(name_or_value, name) == 0)// сравнение без знаков равно
			{
				free(name_or_value);
				name_or_value = ft_strchr(env[i], '=')+1; // pointer marks the symbol in the string// all after =, including =str
				// +1 убирает знак "=
				// name_or_value = name_or_value + 1;
				// ft_putstr_fd(name_or_value, 1);
				// ft_putchar_fd('\n', 1);
				return(name_or_value);
			}
		}
		i++;
	}
	return(0);
}

int cd(t_main *main)
{
	char *command;// функция отрабатывает, но прога завершается и просходит возврат директорию программы
	char **args;
	char *p;
	// int errnum;

	command = main->job->pipe->redir->command;
	args = main->job->pipe->redir->args;

	if (command && !args)
	{
		// p = getenv("HOME");// при удалении HOME в рабочей копии getenv брал копию HOME из оригинала env
		p = ft_getenv(main, "HOME");
		if (p == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 1);
			main->exit = 1; //$? должен вызвать minishell: 1: command not found ()
		}
		else
			chdir(p);
	}
	if (command && args)
	{
		p = *args;
		chdir(p);		
		if (chdir(p) < 0)// if the directory was not found chdir returns -1
		{
			// errnum = errno;
			// main->exit = 1;
			// p = strerror(errnum);
			// printf("%s\n", p);

			ft_putstr_fd("minishell: cd: ", 1);
			ft_putstr_fd(p, 1);
			ft_putstr_fd(": No such file or directory", 1);
			main->exit = 1; // последующая команда $? должна показать значение в структуре main->exit 
			// здесь программа не должна выходить, но выходит по условию в main функции

		}
	}
	return(0);
}

int pwd(t_main *main)
{
	char *command;
	char *flags;
	char buffer[1024];

	//$? = 0; это у нас инициализовано в init_shell там main->exit = 0
	command = main->job->pipe->redir->command;
	flags = main->job->pipe->redir->flags;
	if (getcwd(buffer, 1024) == NULL)
	{
		main->exit = 1;
		printf("Could not get current working directory\n");
	}
	printf("%s\n", buffer);
	return(0);
}

void	process_valid_args( char **s)
{
	char	*str;
	int		i;
	

	str = *s;
	i = 0;
	while (str[i] != '\0' )
	{	
		if(!ft_isdigit(str[i]) && ft_isascii(str[i]) )
		{
			ft_putstr_fd("exit\nminishell: exit: ", 1);
			ft_putstr_fd(str, 1);
			ft_putstr_fd(": numeric argument required", 1);
			exit((unsigned char) -1);//кастануть чтобы выдать 255
		}
		i++;
	}
}

void	process_valid_flags(char *s) // от флагов в парсере лучше отказаться и парсить все в аргументы
{
	char	*str;
	int		i;
	

	str = s;
	i = 0;
	while (str[i] != '\0' )
	{	
		if(!ft_isdigit(str[i]) && ft_isascii(str[i]) )
		{
			ft_putstr_fd("exit\nminishell: exit: ", 1);
			ft_putstr_fd(str, 1);
			ft_putstr_fd(": numeric argument required", 1);
			exit((unsigned char) -1);// пришлось кастануть чтобы выдать 255
		}
		i++;
	}
}

void	process_valid_cmd(t_main *main, char *s) // от флагов в парсере лучше отказаться и парсить все в аргументы
{
	char	*str;
	int		i;
	

	str = s;
	i = 0;
	while (str[i] != '\0' )
	{	
		if(!ft_isdigit(str[i]) && ft_isascii(str[i]) )
		{
			// ft_putstr_fd("minishell: ", 1);
			// ft_putstr_fd(str, 1);
			// ft_putstr_fd(": command not found", 1);
		main->exit = 127;// для команды пишем код возврата вручную // программа не завершается
			break ;
		}
		i++;
	}
}
// Обработка будет в парсере так как парсер не пропускает папку до этапа исполнения
// void	process_folder(t_main *main, char *s) // от флагов в парсере лучше отказаться и парсить все в аргументы
// {
// 	char	*str;
	
// 	str = s;

// 		if(str[0] == '.' && str[1] == '/')
// 		{
// 			ft_putstr_fd("minishell: ", 1);
// 			ft_putstr_fd(str, 1);
// 			ft_putstr_fd(": is a directory", 1);
// 			exit(main->exit = 126);// для команды пишем код возврата ручками
// 		}	
// }

int exit_command(t_main *main)
{
	char *flags;
	char *cmd;
	char ** args;
	int i;

	flags = main->job->pipe->redir->flags;
	args = main->job->pipe->redir->args;
    cmd = main->job->pipe->redir->command;
	i = 0;
	if (cmd && !args)
	{
		ft_putstr_fd("exit\n", 1);
		exit(EXIT_SUCCESS); // выход с кодом 0
	}
	if (cmd && args)
	{
		// char *costil = "-1"; // доработать -2 и тд
		// if ((ft_strcmp(*args,costil)==0)) //костыль потом заменить на обработку в аргументах
		if (*args[0] == '-')
			

		{
			ft_putstr_fd("exit\n", 1);
			exit((unsigned char) -1);// кастануть чтобы выдать 255
		}
		else
			// process_valid_flags(flags);// проверка на цифры вo с выводом ошибки //и сохранением в структуру чтобы можно было вызвать через $?
			process_valid_args(args); // проверка на цифры в аргументе с выводом ошибки //и сохранением в структуру чтобы можно было вызвать через $?
		ft_putstr_fd("exit\n", 1);
		exit(ft_atoi(*args));
	}

	if (cmd && args[i] && !args[i+1])
	{
		if (args)
			process_valid_args(args); // проверка на цифры в аргументе с выводом ошибки //и сохранением в структуру чтобы можно было вызвать через $?
		ft_putstr_fd("exit\n", 1);
		exit((unsigned char)ft_atoi(*args));// выход только с цифрами в аргументе (аргумент можно записать в main->exit) они будут выводится через $?
		// если подавать в аргумент цифру >256 то система дает остаток от деления на 256
	}	
	if ((cmd && args[i] && args[i+1]))
	{
			process_valid_args(args);
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("minishell: exit: too many arguments\n", 1);
			exit(main->exit = 1);
	}

	// if ((cmd && flags[i] && flags[i+1]) && !args) // при подаче 2х флагов второй флаг записывает в аргументы// не войдет в условие
	// // нужно писать все в аргументы
	// {
	// 		process_valid_flags(flags);
	// 		ft_putstr_fd("exit\n", 1);
	// 		ft_putstr_fd("minishell: exit: too many arguments\n", 1);
	// 		exit(main->exit = 1);
	// }	
	// sleep(1000);// for test leaks
	return(0);
}

int env(t_main *main)
{
	char *command;
	char **envir;
	int len;
	int i;
	int j;

	command = main->job->pipe->redir->command;
	envir = main->my_env;
    len= how_many_lines(envir);//  Длина у меня уже увеличилась на один в функции realloc
    // printf("export--->%d\n", len); // проверка кол-ва строк в массиве
	if (command)
	{
	    j = 0;
	    i = 0;
		while(envir[i])
		{
            if (ft_strchr(envir[i], '='))
                printf("%s\n", envir[i]);
            i++;
		}
	}
	return(0);
}

void	double_for_sort_algo(char **envir, int size)
{
    char *tmp;
    int i;
    int j;

    i = -1; //если начать с нуля то TMPDIR выводится первым
    while (++i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (ft_strcmp(envir[i], envir[j]) > 0)
            {
                tmp = envir[i];
                envir[i] = envir[j];
                envir[j] = tmp;
            }
            j++;
        }
    }
}

void	*arrays_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int char_count(const char *str)
{
	int i;

	i = 0;
	if (!(ft_strchr(str, '=')))
		return(0);
	else
	{
		while (str[i] != '=')
		{
			i++;
		}
	}
	return(i);
}

void put_da_brackets( char **e)
{
	char *value1;
	char *value;
	int len;

	len = char_count(*e);
	value1 = (ft_strchr(*e, ('='))); // pointer marks the symbol in the string// all after =, including =str
	value = value1 + 1;//отрубаю после знака равно строку значения// пропускаем знак = через +1
	write(1, *e, len);// пишем до знака равно
	ft_putchar_fd('=', 1); // дописываем
	ft_putchar_fd('\"', 1); //
	ft_putstr_fd(value, 1); //
	ft_putchar_fd('\"', 1); //
}

char** env_recorder(t_main *main)
{
    char **e;
    int length;

    length = how_many_lines((char **) main->my_env);
    e = (char **) malloc(sizeof(char *) * (length + 1));

    int i = 0;
    while (main->my_env[i] != NULL) // запись из оригинала в замолоченный двумерный массив с размером рядов оригинала
    {
        e[i] = main->my_env[i];// лучше записывать через индекс
        i++;
    }
	e[i]=NULL;
    return(e);
}

int check_doubles(char **args, char **en)
{
	char *a_name;
	int len;
	char *e_name;
	int len2;

	while (*en != NULL)
	{
		if(ft_strcmp(*args, *en) == 0)
			return(1);
		else if((ft_strchr(*args, '=')) && !(ft_strchr(*en, '=')))
		{
			len= char_count(*args); // замер до равно
			a_name = ft_substr(*args, 0, len); // отрезать до равно получается арг без равно
			if (ft_strcmp(a_name, *en) != 0) // полное несоответствие строк до знака = и освобождение указателя
				free(a_name);
			if(ft_strcmp(a_name, *en) == 0) // сравнение без знаков равно
			{
				free(*en);
				*en =ft_strdup(*args);
				free(a_name);
				return(1);
			}
		}
		else if((ft_strchr(*args, '=')) && (ft_strchr(*en, '='))) // если и арг и env со знаком =
		{
			len= char_count(*args);
			len2 = char_count(*en);
			a_name = ft_substr(*args, 0, len); // получ арг до знака равно
			e_name = ft_substr(*en, 0, len2); // получ env до знака равно
			if (ft_strcmp(a_name, e_name) != 0) // полное соответствие строк до знака =
			{
					free(e_name);
					free(a_name);
			}
			if (ft_strcmp(a_name, e_name) == 0) // полное соответствие строк до знака =
			{
				free(*en);
				*en =ft_strdup(*args);// перезапись
				free(a_name);
				free(e_name);
				return(1);
			}
		}
		else if(!(ft_strchr(*args, '=')) && !(ft_strchr(*en, '=')))
		{
			if(ft_strcmp(*args, *en) == 0) // полное соответствие строк без знака =
				return(1);
		}
		else if(!(ft_strchr(*args, '=')) && (ft_strchr(*en, '=')))
		{
			len= char_count(*en); // переопределение и замер до равно
			e_name = ft_substr(*en, 0, len); // отрезать до равно получается en без равно
			// e_name = read_name(*en);
			if (ft_strcmp(*args, e_name) != 0) // полное соответствие строк до знака =
				free(e_name);
			if(ft_strcmp(*args, e_name) == 0)// сравнение без знаков равно
			{ 
				free(e_name);
				return(1);
			}
		}
		en++;
	}

	return(0);
}

int checker (char **a, char **e)
{
	if (check_doubles(a, e) == 1)
		return(1);
	else
		return(0);
}

void check_args(char **a)
{
	if (ft_strchr (*a, '_')) // допустимый символ в аргументе
		return;
	if (!ft_isalpha(*a[0])) // если первый  символ не буква то сообщение об ошибке
	{
		ft_putstr_fd ("minishell: export: `", 1);
		ft_putstr_fd (*a, 1);
		ft_putstr_fd ("': not a valid identifier", 1);
		ft_putchar_fd ('\n', 1);
	}	
}

int export(t_main *main)
{
	char *command;
	char **args;
	char **envir;
	int len;
    int i;
	int flag;

	// envir = main->my_env;	// env в алфавитном порядке но нет утечек
    envir = env_recorder(main);// копия чтобы в env не было алфавитного порядка, утечки были и я их убрал
    command = main->job->pipe->redir->command;
	args = main->job->pipe->redir->args;
	
	len = how_many_lines(envir);
	i = 0;
	if (command && !args)
	{	
        // len= how_many_lines(envir);// Длина у меня уже увеличилась на один в функции realloc
        // printf("export--->%d\n", len); // проверка длины после
		double_for_sort_algo(envir, len);
		while( envir[i] != NULL)
		{
			ft_putstr_fd("declare -x ", 1);
			if (!(ft_strchr(envir[i], '=')))// печать строки без знака =
			{
				ft_putstr_fd(envir[i], 1);
				ft_putchar_fd('\n', 1);
			}
			else // печать строки со знаком =
			{
				put_da_brackets(&envir[i]);// ставим кавычки
				ft_putchar_fd('\n', 1);
			}
			if(envir[i] == NULL)
					return(1);
			i++;
		}
		free(envir);// убирает только основной массив подмассивы не трогаем иначе теряются указатели на подстроки
	}
	else
	{
			
			flag = 0;
			i = 0;// первый аргумент нулевой
			len = how_many_lines(envir);
			// sleep(5);
			// printf("here\n");
			while (*args != NULL)// в цикле реалок еще на один аргумент с каждым новым аргументом
			{
				check_args(args);// проверка на допустимые символы
				flag = checker(args, envir);
				if (flag != 1)
				{
				envir = (char **)ft_new_memory_alloc(envir,(sizeof(char*)*(len + 2))); // обязательно нужно указывать на размер чего-то (в данном случае чаров)
				envir[len] = *args;// в выделенную ячейку добавляем аргумент по индексу длины рядов массива, ставим аргумент в конце массива
				envir[len + 1] = NULL; //сместили указатель на ноль по индексу длины рядов массива
				len++; //Длина у меня уже увеличилась на один в функции realloc и не нужно прибавлят
				}
				flag = 0;
				args++; //переход к следующему аргументу
			}
		copy_env2(main, envir);
	}
	// free(envir);
	// arrays_free(envir);
	// sleep(1000);// for test leaks
	return(0);
}

int checker2 (t_main *main, char **a, char **e)
{
	if ((check_string_to_eraze(main,a,e) == 1) || (check_string_to_eraze2(main, a, e) == 1))
		return(1);
	else
		return(0);
}

int check_string_to_eraze2(t_main *main, char **args, char **en)// проверка наличия переменных без знака =
{
	int i;
	int len;

	// len = how_many_lines(en);
	// printf("Before___%d\n", len);
	i = 0;
	while (en[i] != NULL)
	{
		if(!(ft_strchr(*args, '=')) && !(ft_strchr(en[i], '=')) )
		{
			if(ft_strcmp(*args, en[i]) == 0)// сравнение без знаков равно
			{
				free(en[i]);
				while(en[i])
				{
					en[i] = en[i+1]; // смещаем указатель на следующий для всех элемнтов после того как я зафришил
					i++;
				}
				len = how_many_lines(en);
				// printf("After____%d\n", len);
				en = (char **)ft_new_memory_alloc(en,(sizeof(char*)*(len))); // просто лен так как уменьшили на один элемент
				// while (*en != NULL)
				// {
				// 	printf("--->%s\n", *en);
				// 	en++;
				// }
				copy_env2(main, en);
				// free(en);
				return(1);
			}
		}
		i++;
	}
	return(0);
}

int check_string_to_eraze(t_main *main, char **args, char **en)// проверка наличия переменных со знаком =
{
	char *name;
	int len;
	int i;

	i = 0;
	while (en[i] != NULL)
	{
		if(!(ft_strchr(*args, '=')) && (ft_strchr(en[i], '=')) )
		{
			len= char_count(en[i]); // замер до равно (длина строки до =)
			name = ft_substr(en[i], 0, len); // отрезать до равно получается en без равно
			if(ft_strcmp(*args, name) != 0)
				free(name);
			if(ft_strcmp(*args, name) == 0)// сравнение без знаков равно
			{
				// len = how_many_lines(en);//для проверки
				// printf("before-->%d", len);
				free(en[i]);
				while(en[i])
				{
					en[i] = en[i+1]; // смещаем указатель на следующий для всех элемнтов после того как я зафришил
					i++;
				}
				len = how_many_lines(en);// переопределение лен (длина массива строк)
				en = (char **)ft_new_memory_alloc(en,(sizeof(char*)*(len))); // просто лен так как уменьшили на один элемент
				// len = how_many_lines(en);
				// printf("after-->%d", len);
				copy_env2(main, en);
				return(1);
			}
		}
		else 
			return(0);
		i++;
	}
		// if (name)
		// 	free(name);
	return(0);
}

int unset(t_main *main)
{
	char *command;
	char **args;
	char **envir;

    command = main->job->pipe->redir->command;
	args = main->job->pipe->redir->args;
	// envir = main->my_env;
	envir = env_recorder(main);

	while (command && args && *args != NULL)
	{
		checker2 (main, args, envir);
		// if(checker2 (args, envir)== 1)
		// 	copy_env3(main, envir);
		args++;
	}
	// while (*envir != NULL)
	// {
	// 	printf("%s", *envir);
	// 	envir++;
	// }
	return(0);
}

// int process_ready_exe(t_main *main)
// {
// 	char *command; 
// 	char **args;
// 	char **envir;
// 	int fork_res;
// 	int res;

// 	command = main->job->pipe->redir->command;
// 	args = main->job->pipe->redir->args;
// 	envir = main->my_env;

// 	fork_res = fork();
// 	if (fork_res == 0)//  d proc
// 	{
// 		res = execve(command, args, envir);
// 		if (res == -1)// if no execution then we go out from d process
// 			exit(1);
// 	}
// 	if (fork_res > 0)
// 		wait(NULL); // waiting for the daughter to finish
// 	// printf("%d\n", (execve(exe2, args, envir)));
// 	return(0);
// }

int process_exe(t_main *main)
{
	char *command; 
	// char **args;
	char **envir;
	char **binar;
	char *path;
	char *exe;
	char *exe2;
	int i;
	// int fork_res;
	// int res;
	int status;
	status = 0;

	command = main->job->pipe->redir->command;
	char **argv;
	envir = main->my_env;
	i = 0;

	// process_folder(main, command); // на обработке у Мишы
	path = ft_getenv(main, "PATH"); // получаем PATH без равно
	if(!path)
		return 0;
	binar = ft_split(path, ':');// записали path в двумерный массив
	// while (binar[i] != NULL)
	// {
	// 	printf ("%s\n", binar[i]);
	// 	i++;
	// }
	// i = 0; 
	// ls command note: https://scriptingosx.com/2017/08/terminal-primer-part-4-commands/
	// ls ~/Desktop сработало // с 
    // struct dirent *pDirent;
    // DIR *pDir = binar[i];
	// pDirent = NULL;

    //     // Ensure correct argument count.

    //     // Ensure we can open directory.
	// // 	while (binar[i] != NULL)
	// // 	{
			
	// // 		pDir = opendir (binar[i]);
	// // 		if (pDir == NULL) 
	// // 		{
	// // 			printf ("Cannot open directory '%s'\n", binar[i]);
	// // 			i++;
	// // 		}
	// // 		else
	// // 			readdir(pDir);
	// // 		// i++;
	// // 	}

	// // while ((readdir(binar[i])) != NULL) 
	// // {
    // //         printf ("[%s]\n", pDirent->d_name);
	// // 		binar++;
    // // }
	// 	pDir = opendir(binar[i]);
	// 	readdir(pDir);

    //     // Close directory and exit.

    //     closedir (pDir);
    //     return 0;
    // {
    DIR *folder;
    struct dirent *entry;
    int files = 0;
	int res;
	

	while (binar[i] != NULL)
	{
		// printf ("%s\n", binar[i]);
		folder = opendir(binar[i]);
		if(folder == NULL)
		{
			// printf ("->%s\n", binar[i]);
			// perror("Unable to read directory");
			// return(1);
			i++;
		}
		else
		{
			printf ("--->%s\n", binar[i]);
			puts("Directory is opened!");
			while( (entry=readdir(folder)) )
			{
				files++;
				// printf("File %d: %s\n", files, entry->d_name);
				if (ft_strcmp(entry->d_name, command) == 0)
				{
					// char *argv_str = "ls -la";
					argv = args_to_argv_recorder(main);
					// if (args == NULL)
					// {
					// 	args = ft_split(argv_str, ' ');
					// }
					// args = ft_split(argv_str, ' ');
					ft_putstr_fd("Command found\n", 1);
					exe = ft_strjoin(binar[i], "/");
					exe2 = ft_strjoin(exe, command);
					// ft_putstr_fd(exe2, 1);
					// ft_putstr_fd(*args, 1);
					i = 0;
					while(argv[i] != NULL)
					{
						ft_putstr_fd(argv[i], 1);
						ft_putchar_fd('\n', 1);
						i++;
					}
					res = execve(command, argv, envir);
					i = 0;
					while(argv[i] != NULL)
					{
						ft_putstr_fd(argv[i], 1);
						ft_putchar_fd(' ', 1);
						i++;
					}
					// printf("%s", *args);
					ft_putnbr_fd(res, 1);
					return(1);
				}
				
			}
		}
		// {
		// 	while( (entry=readdir(folder)) )
		// 	{
		// 		files++;
		// 		printf("File %3d: %s\n",
		// 				files,
		// 				entry->d_name);
		// 	}
		// }
    	// closedir(folder); //
		// puts("Directory is closed!");
		i++;
	}
    return(0);
}

	// while (binar[i] != NULL)
	// {
	// 	exe = ft_strjoin(binar[i], "/");
	// 	exe2 = ft_strjoin(exe, command);
	// 	// printf("exe2-->%s\n", exe2);
	// 	fork_res = fork();
	// 	if (fork_res == 0)// daughter
	// 	{
	// 		res = execve(exe2, args, envir);		
	// 		// if (res == -1)// if no execution then we go out from d process
	// 		// {
	// 		// 	printf("Error execve\n");
	// 		// 	free(exe2);
	// 		// 	main->exit = 1; // из дочки этот код идет в статус как 256
	// 		// }
	// 		// else
	// 		// 	main->exit = 0;
	// 	}

	// 	// printf("%d\n", (execve(exe2, args, envir)));
	// 	// res = execve(exe2, args, envir); //перезапись res и присвоение -1 (это код сработает только если не будет отработан бинарник
	// 	// и результат будет использован ниже в process_valid_cmd
	// 	free(exe);
	// 	free(exe2);
	// 	i++;
	// }
	// if (fork_res > 0)
	// {
	// 	waitpid(fork_res, &status, 0); // waiting for the daughter to finish
	// 	main->exit = WEXITSTATUS(status); // кладем в exit 1 (если статус 256)
	// 	// status = 0;
	// 	// ft_putstr_fd("status number is\n", 1);
	// 	// ft_putnbr_fd (WEXITSTATUS(status), 1); // запись кода выхода 1
	// 	// write(1, "\n", 1);
	// 	// ft_putnbr_fd (status, 1);// code 256 = 1
	// 	// printf ("main_>exit is\n");
	// 	// ft_putnbr_fd (main->exit, 1);
	// 	// write(1, "\n", 1);
	// 	// printf("parent id is\n");
	// 	// ft_putnbr_fd (fork_res, 1);// ID дочки
	// 	// write(1, "\n", 1);
	// }
	// // printf("%d\n", (execve(exe2, args, envir)));
	// // fork_res = fork();
	// // if (fork_res == 0)//  d proc
	// // if (status == 1 || status == 256) // если команда не сработала в бинарниках status = 1 or 256
	// if (main->exit == 1) // если команда не сработала в бинарниках status = 1 or 256
	// {
	// 	// fork_res = fork();
	// 	// if (fork_res == 0)
	// 		process_valid_cmd(main, command);// проверка на несущетсвующую команду
	// 	// if (fork_res > 0)
	// 	// {
	// 	// waitpid(fork_res, &status, 0); // waiting for the daughter to finish
	// 	// main->exit = WEXITSTATUS(status);
	// 	ft_putnbr_fd (status, 1);// code 256 = 1
	// 	ft_putnbr_fd (main->exit, 1);// code 256 = 1
	// 	// ft_putstr_fd("minishell: ", 1);
	// 	// ft_putstr_fd(command, 1);
	// 	// ft_putstr_fd(": command not found", 1);
	// 	// }
	// }
	// // ft_putnbr_fd (main->exit, 1); на выходе код 127

	// arrays_free(binar);
	// return(0);
// }

void process_builtins_and_divide_externals(t_main *main)
{
	char *command;

	command = main->job->pipe->redir->command;
	if (ft_strncmp(command, "echo", 4) == 0)
		echo(main);
	else if (ft_strncmp(command, "cd", 2) == 0)
		cd(main);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		pwd(main);
	else if(ft_strncmp(command, "export", 6) == 0)
		export(main);
	else if(ft_strncmp(command, "unset", 5) == 0)
		unset(main);
	else if(ft_strncmp(command, "env", 3) == 0)
		env(main);
	else if(ft_strncmp(command, "exit", 4) == 0)
		exit_command(main);
	else
	{
		// process_folder(main, command);// обработка на этапе парсера
		// process_ready_exe(main); // если подается готовая команда то она здесь выполнится
		process_exe(main);
	}
}


