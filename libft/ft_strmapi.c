/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:33:10 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 22:31:10 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length;
	int		i;
	char	*newstring;

	if (s == 0)
		return (0);
	length = ft_strlen(s);
	newstring = (char *)malloc(sizeof(char) * length + 1);
	if (newstring == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		newstring[i] = f(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
