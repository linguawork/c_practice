   
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include <unistd.h>



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

   int main ()
   {
		char *args;
		char *env;
		args = "abc=123";
		env = "cds";
		char *args2;
		args2= "abc=234";
		char *a_name;
		char *a_name1;
		char *a_name2;
		char *a2_name1;
		char *e_name;
		int len;

			len = char_count(args);
            a_name = (ft_strchr(args, '=')); // =___
			printf("with = sign and on, the value is %s\n", a_name); //=tail

			a_name2 = a_name + 1;
			printf("without = sign,the value is %s\n", a_name2);//tail
			

			// a_name1 = ft_itoa(write(1, args, len));// пишем до знака равно// сразу печатает
			// printf("cutting name up to = with itoa, value is%s\n", a_name1);// не печатает все


			// len = char_count(args2);
			// // a2_name1 = (char *)write(1, args2, len);// пишем до знака равно
			// a2_name1 = (char *)read(1, args2, len);// пишем до знака равно
			// write(1, "\n", 2);
			// printf("cutting name up to without itoa(casting char*)%s\n", a2_name1);// не сохраняет


			

			// printf("3_ I need this>%s\n", a_name); // эти варианты печатают все что после знака равно
			// printf("4__>%s\n", a_name--);// манипуляции с минусами не помогают
			// printf("5__>%s\n", a_name-1);
			// printf("5__>%s\n", a_name-2);
			// printf("6__>%s\n", --a_name);

			// strcpy();
			char *str; // единст модель без маллока которая может скопировать name without =value
			len = char_count(args);
			printf("%d", len); // до знака равно
			ft_strlcpy(str, args,len+1);// +1 под термин ноль
			printf("%s", str);

		return(0);
   }




