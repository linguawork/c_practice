/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:30:19 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:31:54 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*result;
	int		i;

	result = (char *)b;
	i = 0;
	while (len != 0)
	{
		result[i] = c;
		i++;
		len--;
	}
	return (b);
}
