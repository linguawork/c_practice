/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:22:40 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:29:03 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*line1;
	unsigned char	*line2;
	size_t			i;

	line1 = (unsigned char *)s1;
	line2 = (unsigned char *)s2;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (i < n)
	{
		if (line1[i] != line2[i])
		{
			return (line1[i] - line2[i]);
		}
		i++;
	}
	return (0);
}
