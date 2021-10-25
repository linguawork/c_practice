/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:02:40 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 22:32:49 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	k;

	k = 0;
	while (s[k])
		k++;
	while (k >= 0)
	{
		if (s[k] == c)
			return ((char *)s + k);
		k--;
	}
	return (NULL);
}
