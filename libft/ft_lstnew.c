/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:57:08 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/27 14:03:10 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->next = NULL;
	result->previous = NULL;
	if (content == NULL)
	{
		result->content = NULL;
		result->content_size = 0;
		return (result);
	}
	result->content_size = content_size;
	result->content = (void *)content;
	return (result);
}
