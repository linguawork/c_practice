/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:10:15 by areggie           #+#    #+#             */
/*   Updated: 2021/05/20 22:38:09 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int pwd(char *command, char *flags);

void process_externals(char *s)
{
    printf("worked in externals\n");
}

int echo(char *command, char **args,	char *flags)
{
	if (command != '\0')
	{
		if(!(flags) || !(args))
			fputc('\n', stdout);
		else if (ft_strncmp(flags, "-n", 2) == 0)
			fputc('\n', stdout);
		else if (ft_strncmp(flags, "-", 1) == 0)
			fputc('-', stdout);
		else 
			(fputs(flags, stdout));

		if(*args)
			fputc(*args, stdout);
	}
	// fputc('\n', stdout);
	return(0);
}

int cd(char *command, const char **args, char *flags) 
// функция отрабатывает, но прога завершается и просходит возврат директорию программы
{
	pwd (command, flags); //проверка для отработки cd
	const char *p;
	
	if (*args != NULL)
	{
		
		p = *args;
		// printf("%s", args[0]);
		chdir(p);
		// printf("%s\n", p);
		pwd (command, flags); //проверка для отработки cd
	}
	else
		{
			p = getenv("HOME");
			if (p == NULL)
			{
				printf("There is no HOME env var\n");
			}
			// else
			// {
			// 	chdir(p);
			// 	pwd (command, flags); //проверка для отработки cd
			// }
		}	
	if (chdir(p) < 0)
	{
		perror(p);
		return(1);
	}
	return(0);
}

int pwd(char *command, char *flags) 
{

	char buffer[1024];
	
	// if (*flags != NULL) // по сабжекту не нужно отрабатывать аргументы
	// 	{
	// 		printf("Too many arguments\n");
	// 		return(1);
	// 	}
	if (getcwd(buffer, 1024) == NULL)
		{
			printf("Could not get current working directory\n");			
		}
	printf("%s\n", buffer);
	return(0);
}


int exit_command(char *command, char *flags) 
{
	if (flags != NULL )
		exit(1);
	exit(1);
}

int env(char *command, const char **args) 
{
	const char **envir;
	extern char **environ; 

	envir = (const char **)environ;
	if ((command && *args == NULL) || (command && *args != NULL)) 
	{
		while(*envir)
		{
			printf("%s\n", *envir);
			envir++;
		}
		
	}
	return(0);
}

void	double_for_sort_algo(const char **args, int size)
{
	// source: https://stackoverflow.com/questions/18408558/logic-challenge-sorting-arrays-alphabetically-in-c
	const char *tmp;
	int i;
	int j;

	i = -1; //если начать с нуля то TMPDIR выводится первым
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(args[i], args[j]) > 0) 
			{
				tmp = args[i];
				args[i] = args[j];
				args[j] = tmp;
			}
			j++;
		}
	}		
}

int how_many_lines(const char **a)
{
	int i;
	const char **env;

	i = 0;
	env = a;
	while(env[i])
	{
		i++;
	}
	return(i);
}

// int argsnum(const char **b)
// {
// 	int i;
// 	const char **env;

// 	i = 0;
// 	env = b;
// 	while(env[i])
// 	{
// 		i++;
// 	}
// 	return(i);
// }

// const char ** calloc_args(const char **c)
// {
// 	int argnum;
	 
// 	argnum = argsnum(c);
// 	c = (const char **)ft_calloc(sizeof(char *), argnum+1); // надо выделять под аргс иначе сега
// 	return(c);
// }



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

void reconstruct(const char **args)
{
	char **splitstr;
	char *str; 
	int strlen; 
	strlen = ft_strlen(*args);
	str = (char *)malloc(sizeof(char*)*(strlen + 3));

	str[0] = 0;
	splitstr = ft_split(*args,'=');// можно в одинарных (это инт и он символ)
	strcpy(str, splitstr[0]);
	strcat(str, "=");
	strcat(str,"\"");// нельзя в одинарных (это инт) в двойных это char pointer
	strcat(str, splitstr[1]);
	strcat(str,"\"");// нельзя в одинарных (это инт) в двойных это char pointer
	*args = str;
	// printf("___%s\n", *args);
	// free(str);
	arrays_free(splitstr);
}

void withzero(const char **args)
{
	// char **splitstr;
	char *str; 
	int strlen; 
	strlen = ft_strlen(*args);
	str = (char *)malloc(sizeof(char*)*(strlen + 3));

	str[0] = 0;
	// splitstr = ft_split(*args,'=');// можно в одинарных (это инт и он символ)
	strcpy(str, *args);
	// strcat(str, "=");
	strcat(str,"\"\"");// нельзя в одинарных (это инт) в двойных это char pointer
	*args = str;
	printf("__%s\n", *args);
	// free(str);
}

void check_equal_sign_add_quotes(const char ** args)
{
	int i; 
	int j;
	int flag;
	 
	flag = 0;
	
	i = 0; 
	while(args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (args[i][j] == '=' && args[i][j+1] != 0)
				reconstruct(&args[i]);
			else if (args[i][j] == '=' && args[i][j + 1] == 0)
				withzero(&args[i]);
			++j;
		}
		++i;
	}
}

void reconstruct2(const char **args, const char **envir)
{
	char **splitstr;
	char **splitenvir;
	// char *s;
	int i;
	int len;
	int len2;
	int flag;

	// s[0] = 0;
	flag = 0; 
	i = 0;
	splitstr = ft_split(*args,'=');// можно в одинарных (это инт и он символ)	
	// strcpy(s, splitstr[0]); // пока сделаем без маллока
	// strcat(s, "=");
	len = ft_strlen(splitstr[0]);// для сравнения в strncmp
	len2 = ft_strlen(splitstr[1]);// длина хвоста аргумента
	while(envir[i])
	{
		// printf("%s ||| %s\n", );
		// if (strncmp(envir[i], splitstr[0], 4) == 0)
		// 	printf("OKEY\n");
		if (flag == 0 && ft_strncmp(envir[i], splitstr[0], len) == 0) // сравнение без знака равно
		{
			printf("inside\n");
			splitenvir = ft_split(envir[i], '=');
			free((void *)envir[i]); //переназначение типа (так как free требует  void*)
			envir[i] = (char *)malloc(sizeof(char*)*(len +1 + len2 + 1));
			strcpy((char *)envir[i], splitenvir[0]);
			strcat((char *)envir[i], "=");
			strcat((char *)envir[i], splitstr[1]);
			printf("%s\n", envir[i]);
			arrays_free(splitstr);
			flag = 1;
		}
		// printf("WTF\n%s\n", envir[i]);
		// while(envir[i])
		// {	
		// 	printf("-->%s\n", envir[i]);
		// 	i++;
		// }
		i++;
		
	}

	// arrays_free(splitstr);
}

void check_duplicates(const char ** args, const char **envir)
{
	int i; 
	int j;
	int flag;
	 
	flag = 0;
	
	i = 0; 
	while(args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if ((args[i][j] == '=' && args[i][j+1] != 0) || \
			(args[i][j] == '=' && args[i][j + 1] == 0))
				reconstruct2(&args[i], envir);
			++j;
		}
		++i;
	}
}

int char_count(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '=')
	{
		i++;
	}
	return(i);
}

void divider(const char **args)
{
	char *name;
	char *value;
	char *s;
	int i;
	int len;
	int len2;

	len = char_count(*args); // lenght до знака равно
	s = (char *)malloc(sizeof(char *)*(len+1 + len2+1+3));
	s[0] = 0;
	name = ft_substr(*args, 0, len);
	value = ft_strdup(ft_strchr(*args, ('='+1)));
	len2=ft_strlen(value);


	strcpy(s, name); // пока сделаем без маллока
	strcat(s, "=");
	strcat(s, "\"");
	strcat(s, value);
	strcat(s, "\"");
	*args = s;
	free(s);
}

int export(char *command, const char **args) 
{
	const char **envir;
	extern char **environ; 
	const char *prefix;
	int len;
	int newlen;

	prefix = "declare -x ";
	len = how_many_lines((const char **)environ);
	envir = (const char **)malloc(sizeof(char*)*(len+1));
	
	int i = 0;
	while (environ[i]) // запись из оригинала в замолоченный двумерный массив с размером рядов оригинала
	{
		envir[i] = ft_strdup(environ[i]);// лучше записывать через индекс
		i++;
	}
	envir[i] = NULL;
	newlen= how_many_lines(envir);
	i = 0;
	if (command && *args == NULL) 
	{
		double_for_sort_algo(envir, newlen);
		while(envir[i])
		{	
			envir[i] = ft_strjoin(prefix, envir[i]);
			printf("%s\n", envir[i]);
			i++;
		}
	}	
	if (command && *args != NULL)
	{
		// printf("I am working on it\n");
		int i;
		i = 0;
		
		// divider(args);
		check_duplicates(args, envir);
		check_equal_sign_add_quotes(&args[i]);
		while ( i >= 0 && args[i] != NULL)
		{
			newlen= how_many_lines(envir);
			printf("%d\n", newlen);
			envir = (const char **)realloc(envir,(sizeof(char*)*(newlen + 2))); // обязательно нужно указывать на размер чего-то (в данном случае чаров)
			envir[newlen + 1] = NULL; // сместили указатель на ноль по индексу длины рядов массива
			// printf("test%s\n", args[i]);
			envir[newlen] = args[i];// в выделенную ячейку добавляем аргумент по индексу длины рядов массива
			newlen = newlen + 1;
			i++;
			newlen= how_many_lines(envir);
			printf("%d\n", newlen);
		}
		
		i = 0; 
		double_for_sort_algo(envir, newlen);
		while(envir[i])
		{	
			envir[i] = ft_strjoin(prefix, envir[i]);
			printf("%s\n", envir[i]);
			i++;
		}
	}
	return(0);
}



void process_builtins_and_divide_externals(char *command, const char **args, char *flags)
{

	if (ft_strncmp(command, "echo", 4) == 0)
		echo(command, args, flags);
	else if (ft_strncmp(command, "cd", 2) == 0)
		cd(command, args, flags);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		pwd(command, flags);
	else if(ft_strncmp(command, "export", 6) == 0)
		export(command, args); 
	else if(ft_strncmp(command, "unset", 5) == 0)
		printf("unset\n");
	else if(ft_strncmp(command, "env", 3) == 0)
		env(command, args);
	else if(ft_strncmp(command, "exit", 4) == 0)
		exit_command(command, flags);
	else
		process_externals(command);
	}



int main ()
{

	// // EXPORT WORKING
	// // в парсере нужно обработать если первый символ аргумента цифра
	// // это невалидный кейс
	// char *command;
	// const char **args;
	// char *flags;
	
	// command = "export";
	// args = (const char **)ft_calloc(sizeof(char *), 7); // надо выделять под аргс иначе сега
	// args[0] = "aa28"; // при подаче аргумента c $(знак доллара убран на этапе парсера)
	// // args[1] = "bb29";
	// // args[2] = "ddd====bcd";//после первого знака равно должно уходить в строку ddd="===bcd"
	// // args[3] = "ddd====bcda";//выводит два раза - должна быть перезапись
	// // args[4] = "abc=";//ok
	// // args[5] = "abcd=";//ok
	
	// // args[0] = "USER=fignigno"; 
	// // args[1] = "PWD=/Users/areggie/Desktop";// отрабатывает с заменой но пишет 2 раза
	// // отрабатывает с заменой но пишет 2 раза
	// // так как в check_equal_sign_add_quotes(&args[i])  envir[newlen] = args[i]
	// // если отключить то выводит по одному разу но без кавычек/ но тогда не будет выводить много аргументов

	
	// // args[1] = "ddd=bcda";//выводит два раза - должна быть перезапись
	// process_builtins_and_divide_externals(command, args, flags);
	// // sleep(100);
	

	// // ENV WORKING
	// char *command;
	// char **args;
	// char *flags;
	
	// command = "env";
	// args = (char **)ft_calloc(sizeof(char *), 1); // надо выделять под аргс иначе сега
	// // аргументы не нужно подавать!!! А если они подаются то они должны игнорится
	// *args = "HOME"; // Аргумент игнорится и при подаче аргумента (знак доллара убран на этапе парсера)
	// process_builtins_and_divide_externals(command, args, flags);

	
	// // EXIT WORKING
	// char *command;
	// char **args;
	// char *flags;
	
	// command = "exit";
	// flags = (char *)ft_calloc(sizeof(char *), 1);
	// flags = "1"; // при подаче аргумента c exit тоже выходит
	// process_builtins_and_divide_externals(command, args, flags);
	
	// //PWD WORKING
	// char *command;
	// char **args;
	// char *flags;
	
	// command = "pwd";
	// flags = (char *)ft_calloc(sizeof(char *), 1);
	// // flags = "1"; // при подаче аргумента выдает сообщение
	// process_builtins_and_divide_externals(command, args, flags);

	
	// //CD WORKING
	// char *command;
	// char **args;
	// char *flags;
	
	// command = "cd";
	// args = (char **)ft_calloc(sizeof(char *), 1);
	// *args = "/Users/areggie/Desktop/"; // отработывает абсолютный путь выход  из /Users/areggie/Desktop/practice
	// // *args = "../../Music/"; // отработывает относительный путь выход  из /Users/areggie/Desktop/practice
	// // *args = "."; // отрабатывает
	// process_builtins_and_divide_externals(command, args, flags);


	// //ECHO WORKING //  отрегулировать Аргументы и флаги
	// char *command;
	// char *flags; // options in the subject
	// char **args;
	
	// command = "echo";
	// // была сега так как я не выделял память для двумерного массива
	// // выделил память и начал выводить аргумент
	// args = (char **)ft_calloc(sizeof(char *), 1);
	// *args = "std";
	// process_builtins_and_divide_externals(command, args, flags);
	return(0);
}