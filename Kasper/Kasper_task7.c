/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kasper_task7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:47:41 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 14:50:02 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()

{

	unsigned int i;

	for (i = 10; i >= 0; --i) // i is always 10, so it is eternal cycle
    	printf("He!");

	return 0;
}