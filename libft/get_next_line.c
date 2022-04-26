/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:26:03 by areggie           #+#    #+#             */
/*   Updated: 2022/04/26 22:16:10 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	see_remnants_else_if1(char *r, char **l)
{
	*l = ft_strdup(r);
	if (!(*l))
		return (-1);
	ft_bzero(r, ft_strlen(r));
	return (0);
}

int	see_remnants_else_if2(char **l)
{
	*l = ft_calloc(1, 1);
	if (!(*l))
		return (-1);
	return (0);
}

int	see_remnants(char *rem, char **line)
{
	char		*ptr;

	ptr = NULL;
	if (rem[0] != '\0')
	{
		ptr = ft_strchr(rem, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = ft_strdup(rem);
			if (!(*line))
				return (-1);
			ptr++;
			ft_strlcpy(rem, ptr, BUFFER_SIZE + 1);
			return (1);
		}
		else
			see_remnants_else_if1 (rem, line);
	}
	else
		see_remnants_else_if2 (line);
	return (0);
}

int	record_to_line(char **line, char *buffer)
{
	*line = ft_strjoin(*line, buffer);
	if (!(*line))
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	remnants[BUFFER_SIZE + 1];
	int			whatwasread;
	char		buffer[BUFFER_SIZE + 1];
	char		*ptr;
	int			flag;

	ptr = NULL;
	if (!line || ((read(fd, ptr, 0)) < 0) || BUFFER_SIZE < 1)
		return (-1);
	flag = see_remnants(remnants, line);
	if ((flag == 1) || (flag == -1))
		return (flag);
	buffer[0] = 0;
	whatwasread = 1;
	while (!(ft_strchr(buffer, '\n')) && whatwasread != 0)
	{
		record_to_line (line, buffer);
		whatwasread = read(fd, buffer, BUFFER_SIZE);
		if (!(whatwasread))
			return (0);
		buffer[whatwasread] = '\0';
	}
	process_rem_and_buf(ptr, remnants, buffer);
	record_to_line (line, buffer);
	return (1);
}
