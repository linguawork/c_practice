
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include <unistd.h>


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
			// a_name = ft_substr(*args, 0, len); // отрезать до равно получается арг без равно
			ft_strlcpy(a_name, *args, len + 1);
			if (ft_strcmp(a_name, *en) != 0) // полное несоответствие строк до знака = и освобождение указателя
				en++;// может быть continue
			if(ft_strcmp(a_name, *en) == 0) // сравнение без знаков равно
			{
				free(*en);
				*en =ft_strdup(*args);
				// free(a_name); на стеке
				return(1);
			}
		}
		else if((ft_strchr(*args, '=')) && (ft_strchr(*en, '='))) // если и арг и env со знаком =
		{
			len= char_count(*args);
			len2 = char_count(*en);
			// a_name = ft_substr(*args, 0, len); // получ арг до знака равно
			ft_strlcpy(a_name, *args, len + 1);
			// e_name = ft_substr(*en, 0, len2); // получ env до знака равно
			ft_strlcpy(e_name, *en, len2 + 1);
			if (ft_strcmp(a_name, e_name) != 0) // полное соответствие строк до знака =
			{
					// free(e_name);
					// free(a_name);
					en++;// может быть continue
			}
			if (ft_strcmp(a_name, e_name) == 0) // полное соответствие строк до знака =
			{
				free(*en);
				*en =ft_strdup(*args);// перезапись
				// free(a_name);
				// free(e_name);
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
			// e_name = ft_substr(*en, 0, len); // отрезать до равно получается en без равно
			ft_strlcpy(e_name, *en, len + 1);
			// e_name = read_name(*en);

			if (ft_strcmp(*args, e_name) != 0) // полное соответствие строк до знака =
				// free(e_name);
				en++;// может быть continue
			if(ft_strcmp(*args, e_name) == 0)// сравнение без знаков равно
			{ 
				// free(e_name);
				return(1);
			}
		}
		en++;
	}

	return(0);
}