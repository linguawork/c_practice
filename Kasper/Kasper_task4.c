/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kasper_task4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:10:49 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 14:19:34 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* size of union is 4 bytes in this case

https://www.geeksforgeeks.org/c-language-2-gq/structure-union-gq/#:~:text=When%20we%20declare%20a%20union%2C%20memory%20allocated%20for%20a%20union,union%20test%20is%208%20bytes.

When we declare a union, 
memory allocated for a union variable of the type
is equal to memory needed for the largest member of it,
and all members share this same memory space. 
In below example, "int x" is the largest member. 
Therefore size of union test is 4 bytes.
*/

union boo 
{
    char  a, b, c, d, e, f, g;
    int   x;
    short y;
};


int main()
{
	printf("%lu", sizeof(union boo)); // unsigned long is lu
	
	return 0;
}