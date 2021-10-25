/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:21:34 by areggie           #+#    #+#             */
/*   Updated: 2021/04/11 18:53:38 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ternary(int r, int l, int length)
{
	if (r - l < 0)
		length = 0;
	else
		length = (r - l);
	return (length);
}

void	*strtrim_m_alloc(char	*str, size_t arr_length)
{
	str = (char *)malloc(sizeof(char) * (arr_length + 1));
	if (!str)
		return (NULL);
	else
		return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		right;
	char	*nova;
	int		left;
	int		len;

	left = 0;
	len = 0;
	nova = NULL;
	if (!s1 || !set)
		return (NULL);
	right = ft_strlen(s1);
	while (s1[left] && ft_strchr(set, s1[left]))
		left++;
	while (right && ft_strchr(set, s1[right - 1]))
		right--;
	len = ternary(right, left, len);
	nova = strtrim_m_alloc(nova, len);
	nova[len] = '\0';
	right = 0;
	while (right < len)
		nova[right++] = s1[left++];
	return (nova);
}
