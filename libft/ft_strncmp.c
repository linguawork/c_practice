/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:22:18 by areggie           #+#    #+#             */
/*   Updated: 2021/05/19 20:29:29 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*line1;
	unsigned char	*line2;
	size_t			i;

	line1 = (unsigned char *)s1;
	line2 = (unsigned char *)s2;
	i = 0;
	if (!(n))
		return (0);
	while (i < n && line1[i] != '\0' && line2[i] != '\0')
	{
		if (line1[i] != line2[i])
			return (line1[i] - line2[i]);
		i++;
	}
	return (0);
}
