/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:47:41 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 22:30:28 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	int			i;
	int			j;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	j = 0;
	if (s == NULL && d == NULL)
		return (0);
	if ((!(dstsize)))
		return (ft_strlen(s));
	while (dstsize != 0 && s[i] != 0)
	{
		d[j] = s[i];
		i++;
		j++;
		dstsize--;
	}
	if (dstsize > 0)
		d[j] = '\0';
	else
		d[j - 1] = '\0';
	return (ft_strlen(s));
}
