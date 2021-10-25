/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:14:08 by areggie           #+#    #+#             */
/*   Updated: 2021/04/10 21:00:11 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*t_list_mem_alloc(t_list *element)
{
	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	else
		return (element);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = NULL;
	new_elem = t_list_mem_alloc(new_elem);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
