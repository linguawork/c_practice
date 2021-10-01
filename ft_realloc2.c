
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//source: https://codereview.stackexchange.com/questions/151019/implementing-realloc-in-c/151021

void    *ft_remalloc(void *ptr, size_t len)
{
    void    *result;

    result = (void *)malloc(sizeof(void *) * len);// создаем новую строку с новым размером
	if (!result)
		return(NULL);
	else
	{
    	ft_memset(result, '\0', len);// заполнение нулями на всю длину
        ft_memcpy(result, ptr, len);// копируем поданную строку в новую
	}
    free(ptr);
    return (result);
}



