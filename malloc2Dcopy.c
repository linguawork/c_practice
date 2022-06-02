/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2Dcopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:42:52 by areggie           #+#    #+#             */
/*   Updated: 2022/06/02 10:20:19 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include <stdlib.h>
	#include <stdio.h>

	int ** allocating(int ** array, int nrows, int ncolumns)
	{
		int i; 
		i = 0;
	// int **array;
		array = malloc(nrows * sizeof(int *));
		if(array == NULL)
			{
				// fprintf(stderr, "out of memory\n");
				return 0;
			}
		for(i = 0; i < nrows; i++)
			{
			array[i] = malloc(ncolumns * sizeof(int));
			if(array[i] == NULL)
				{
					// fprintf(stderr, "out of memory\n");
					return 0;
				}
			}
		return array; 
		
	}

	int main()
	{
		int ** arr;
		int rows = 4;
		int coloumns = 4;

		int v[4]={ 3, 2, 1, 0}; 
        int **answers;//or *answers[4];


		answers = allocating(arr, rows, coloumns);

		printf("the size before of 2D array is %lu\n", sizeof(answers));
		
		
		int i;

		i = 0;
		while (i != 4) 
		{
			answers[i] = &v[i]; // recorded subarray to the main array (one element of main has one element of subarray)
			i++;
		}
		
		for(i = 0; i < 4; i++)
		{
	
			//the address is the same
			printf("The main array element's address: %d  has one element %d in the subarray\n", &answers,  *answers[i]);
			
			printf("The main array element: %d  has one element %d in the subarray\n", i,  *answers[i]);
		}

		printf("the size after of 2D array is %lu\n", sizeof(answers));
		
	}