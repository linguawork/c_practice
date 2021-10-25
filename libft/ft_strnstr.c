/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:42:20 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 22:32:06 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[a] != 0 && a < len)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && needle[b] != 0 \
				&& (size_t)b + a < len)
		{
			b++;
			if (b == ft_strlen(needle))
				return ((char *)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
