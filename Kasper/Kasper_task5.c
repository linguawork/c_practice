/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kasper_task5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:17:44 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 14:46:31 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


/*
https://www.includehelp.com/c/size-of-struct-in-c-padding-alignment-in-struct.aspx#:~:text=Above%20is%20the%20alignment%20of,the%20struct%20is%2032%20Bytes.

the size of struct includes padding (пустующие байты) в ячейке на 8 байт

The size may vary depending on the order of
the data types
because sometimes the compiler puts two or more data-types in one cell
	
*/
struct boo {
    char  a;
    int   b;
    short c;
};

int main()
{
	printf("%lu", sizeof(struct boo)); // unsigned long is lu
	
	return 0;
}