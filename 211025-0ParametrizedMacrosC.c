/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParametrizedMacrosC.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:23:00 by areggie           #+#    #+#             */
/*   Updated: 2021/10/25 13:29:51 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	в 7м дне бассейна по плюсам у французов говорится о параметрическом макросе, который стал основой
	для создания шаблонов в языке С++

	Я нашел код и объяснение у индусов：
	https://www.youtube.com/watch?v=SpjiAjmmZk8

	C Programming Tutorial - 73: Parameterized Macros
	на канале Bad Tutorials

*/

#include <stdio.h>
#define SUM(x,y) (x+y)

int main()
{
	int a, b;
	a=15;
	b=20;
	printf("Sum of %d and %d is: %d", a, b, SUM(a,b));

	return 0;
}
