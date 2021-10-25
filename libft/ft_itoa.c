/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:15:10 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 20:33:25 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mem_alloc(char	*str, size_t arr_length)
{
	str = (char *)malloc(sizeof(char) * (arr_length + 1));
	if (!str)
		return (NULL);
	else
		return (str);
}

static int	itlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = NULL;
	len = itlen(n);
	str = ft_mem_alloc(str, len);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len-- - 1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
