/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:52:28 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:29:24 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*first;
	char	*second;
	int		i;
	int		j;

	first = (char *)src;
	second = (char *)dst;
	i = 0;
	j = 0;
	if (src == 0 && dst == 0)
		return (0);
	while (n != 0)
	{
		second[j] = first[i];
		i++;
		j++;
		n--;
	}
	return (dst);
}
