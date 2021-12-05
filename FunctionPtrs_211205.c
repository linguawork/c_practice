/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FunctionPtrs_211205.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:33:37 by areggie           #+#    #+#             */
/*   Updated: 2021/12/05 20:34:49 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.cprogramming.com/tutorial/function-pointers.html

#include <stdio.h>
void my_int_func(int x)
{
    printf( "%d\n", x );
}
 
 
int main()
{
    void (*foo)(int);
    foo = &my_int_func;
 
    /* call my_int_func (note that you do not need to write (*foo)(2) ) */
    foo( 2 );
    /* but if you want to, you may */
    (*foo)( 2 );
 
    return 0;
}