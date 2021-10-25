/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:04:45 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:14:13 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*line;
	unsigned char	chr;
	int				i;

	line = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (n != 0)
	{
		if (line[i] == chr)
			return ((void *)&line[i]);
		i++;
		n--;
	}
	return (0);
}
