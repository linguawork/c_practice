#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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


// 	while(envir[i])
// 	{
// 		if (ft_strncmp(envir[i], splitstr[0], len) == 0) // сравнение без знака равно

// 			splitenvir = ft_split(envir[i], '=');
// 			arrays_free(envir[i]);
// 			envir[i] = (char *)malloc(sizeof(char*)*(len +1 + len2 + 1));
// 			strcpy((char *)envir[i], splitenvir[0]);
// 			strcat((char *)envir[i], "=");
// 			strcat((char *)envir[i], splitstr[1]);
// 		i++;
// 	}

// 	arrays_free(splitstr);
// }

// int main()
// {
//     const char *s = "I love you,darlin======g!";
//     char *out;
// 	char *ft; 

// 	int len; 
// 	len = char_count(s);
// 	ft = ft_strchr(s,'=');
//     out = ft_substr(s, 0, len);
//     printf("in my function:\n");
//     printf("%s\n", out);
//     printf("%s\n", s);
// 	printf("%s\n", ft); // strchr отрезает строку с указанного символа
// }