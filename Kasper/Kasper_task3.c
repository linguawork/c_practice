/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverp2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:00:19 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 14:04:40 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Task to Kaspersky

enter phrase and return its reversed value
for example:

input:  hello Alexander!
output: !rednaxelA olleh

*/


#include <stdio.h>
#include <string.h>

int main()
{
  char str1[100];
	char str2[100];
    
  scanf("%[^\n]s", &str1[0]); // [^\n]  - этот знак исключает пробел из строки чтобы читалось второе слово после пробела
  int len = strlen(&str1[0]); 
  // printf("the len is %d\n", len); for debug
  int i = 0;
  len--;// removing terminator
  while(len != -1) // не выводил ноль поэтому я сделал -1
      str2[i++] = str1[len--];
  // printf("Original Word: %s\n", str1);
  // printf("Reverse word: %s\n", str2);
  printf("%s\n", str2);
  return 0;
}