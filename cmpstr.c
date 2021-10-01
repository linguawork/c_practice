#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void divider(const char **args)
{
	char **splitstr;
	char **splitenvir;
	char *s;
	int i;
	int len;
	int len2;

	s[0] = 0;
	i = 0;
	splitstr = ft_split(*args,'=');// можно в одинарных (это инт и он символ)	
	// strcpy(s, splitstr[0]); // пока сделаем без маллока
	// strcat(s, "=");
	len = ft_strlen(splitstr[0]);// для сравнения в strncmp
	len2 = ft_strlen(splitstr[1]);// длина хвоста аргумента
	while(envir[i])
	{
		if (ft_strncmp(envir[i], splitstr[0], len) == 0) // сравнение без знака равно

			splitenvir = ft_split(envir[i], '=');
			arrays_free(envir[i]);
			envir[i] = (char *)malloc(sizeof(char*)*(len +1 + len2 + 1));
			strcpy((char *)envir[i], splitenvir[0]);
			strcat((char *)envir[i], "=");
			strcat((char *)envir[i], splitstr[1]);
		i++;
	}

	arrays_free(splitstr);
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

// void comparator(const char **args, const char **envir)
// {
// 	while()
	
// }