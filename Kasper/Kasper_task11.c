/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kasper_task11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:07:31 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 15:09:13 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	вывод 40,8 
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
        int  a[10];
        int *b;

        b = calloc(10, sizeof(int));

        printf("%zu, %zu\n", sizeof(a), sizeof(b));

        return 0;
}