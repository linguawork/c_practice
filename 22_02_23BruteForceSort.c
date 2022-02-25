/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_02_23BruteForceSort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:39:43 by areggie           #+#    #+#             */
/*   Updated: 2022/02/23 21:39:48 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//сортировка массива брут форс
void	sort_array(t_vars *vars)
{
	int			j;
	int			i;
	int			temp;

	i = 0;
	while (i < vars->size - 1)
	{
		j = vars->size - 1;
		while (j > i)
		{
			if (vars->sorted_array[j - 1] > vars->sorted_array[j])
			{
				temp = vars->sorted_array[j - 1];
				vars->sorted_array[j - 1] = vars->sorted_array[j];
				vars->sorted_array[j] = temp;
			}
			j--;
		}
		i++;
	}
}