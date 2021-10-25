/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:17:49 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:29:50 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (a == NULL && b == NULL)
		return (dst);
	if (b > a)
	{
		while (len)
		{
			len = len - 1;
			b[len] = a[len];
		}
	}
	if (b <= a)
	{
		ft_memcpy(b, a, len);
	}
	return (dst);
}
