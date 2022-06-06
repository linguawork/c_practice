/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScanfPrintf.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:13:43 by areggie           #+#    #+#             */
/*   Updated: 2022/06/06 14:02:22 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 



/*
The task is from HackerRank:

enter 5 numbers and print them

3 128734612398756 a 314.2340 567.83500000234

 */

int main()
{
	//enter your code
	
	int a = 3; 
	long int b = 128734612398756;
	char c = a;
	double d = 314.2340;
	double d2 = 567.83500000234;

	// scanf ("%d\n %ld\n %c %lf %lf", &a, &b, &c, &d, &d2);

	printf("%d\n%ld\n%c\n%1.3lf\n%1.9lf\n", a, b, c, d, d2); 
	// 1целое.3 - числа после точки
	// 1целое.9 - числа после точки
	
	return 0;
};
