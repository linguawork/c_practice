/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_02_23BubbleAlgo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:34:04 by areggie           #+#    #+#             */
/*   Updated: 2022/02/23 21:34:06 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void bubble_sort_algo(int *order, double *dist, t_all *ptr)
{
	int i;
	int j;
	int tmp;
	int ord;

	i = -1;
	while (++i < ptr->spt_qty)
	{
		j = -1;
		while (++j < ptr->spt_qty - i - 1)
		{
			if (dist[j] > dist[j + 1])
			{
				ord = order[j];
				order[j] = order[j + 1];
				order[j + 1] = ord;
				tmp = dist[j];
				dist[j] = dist[j + 1];
				dist[j + 1] = tmp;
			}
		}
	}
}