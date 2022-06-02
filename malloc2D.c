/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:42:52 by areggie           #+#    #+#             */
/*   Updated: 2022/06/02 09:57:47 by areggie          ###   ########.fr       */
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
		int ** res;

		res = allocating(arr, rows, coloumns);


		printf("%lu", sizeof(res));
		printf)
		
	}