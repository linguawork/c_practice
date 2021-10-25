/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:05:34 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:08:23 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	unsigned char	d;
	int				i;

	first = (unsigned char *)src;
	second = (unsigned char *)dst;
	d = (unsigned char)c;
	i = 0;
	while (n != 0)
	{
		second[i] = first[i];
		if (first[i] == d)
			return ((void *)&second[i + 1]);
		i++;
		n--;
	}
	return (0);
}
