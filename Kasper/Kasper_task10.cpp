/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kasper_task10.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:00:30 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 15:07:03 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
пытался компилить в Си
но не получилось

удалось скомпилить только в СPP 

вывод 3 не 12

*/

#include <iostream>
#include <cstddef> // 

int main()
{
	int a[10];
	ptrdiff_t diff = &a[8] - &a[5];

	printf("%td\n", diff);
	
	return 0;
}