/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:38:35 by areggie           #+#    #+#             */
/*   Updated: 2021/04/11 18:54:53 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	size_t	reallen;

	if (!(s))
		return (NULL);
	reallen = ft_strlen(s);
	if (start > reallen)
		start = reallen;
	if (len > reallen - start)
		len = reallen - start;
	if (start >= reallen)
		return (ft_calloc(1, 1));
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != 0 && (size_t)i != len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
