/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kasper_task6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:28:51 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 14:46:22 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://stackoverflow.com/questions/2084949/comparison-operation-on-unsigned-and-signed-integers

при сравнении и разнице инт и unsigned int compiler changes(casts) int into unsigned
therefore the value of int changes and it may give unexpected results

see the explanation in the link

I kind of guessed and wrote the correct explanation in the code

*/


#include <stdio.h>

void greet(int nr_people) {
        unsigned limit = 3;

        if (nr_people <= limit) // -1 will not enter here, because it is less unsigned 3
		// by going below 0 it will not be with minus sign, it will be max_unsigned_int - 1
                printf("Hi!\n");
        else
                printf("Hello!\n");
}

int main () 
{
	greet(-1);
	return 0;
}