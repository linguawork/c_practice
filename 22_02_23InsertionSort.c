/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_02_23InsertionSort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:35:16 by areggie           #+#    #+#             */
/*   Updated: 2022/02/23 21:35:24 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void insertion_sort_algo(int i, double *spr_array, t_all *ptr)//сортировка вставкой
{
    // int i;
    int whattocompare;
    int j;

    i = -1;
    while (++i < ptr->spt_qty)
    {
        whattocompare = spr_array[i];
        j = i - 1;
        while (j >= 0 && spr_array[j] > whattocompare) 
        {
            spr_array[j + 1] = spr_array[j];//сдвиг на одну ячейку вперед
            j = j - 1;//итератор назад на одну
        }
        spr_array[j + 1] = whattocompare; //сравниваем с той, куда передвинулись
    }
}