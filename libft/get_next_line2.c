/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:33:27 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 21:29:12 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	process_rem_and_buf(char *ptr, char *remnants, char *buffer)
{
	ft_strlcpy(remnants, ft_strchr(buffer, '\n') + 1, (BUFFER_SIZE + 1));
	ptr = ft_strchr(buffer, '\n');
	*ptr = '\0';
}
