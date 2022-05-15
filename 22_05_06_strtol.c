/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_05_06_strtol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:06:27 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 12:13:04 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
http://www.c-cpp.ru/content/strtol-strtoul

related to HackerRank preps in C
*/

//Следующая функция читает десятичные числа из стандартного ввода и возвращает их значения в формате long:
#include <stdio.h>
#include <stdlib.h>

long int read_long()
{
char start[80], *end;
printf("Enter a number: ");
gets (start);
return strtol (start, &end, 10); // возвращает long база- десятичная
}

int main()
{
	long res;
	
	res = read_long();
	
	printf("%ld\n", res);
	
	return 0;
}