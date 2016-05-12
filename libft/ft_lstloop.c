/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:19:00 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/27 16:15:37 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstloop(t_list *lst, void *data, void (*f)(t_list *elem, void *data))
{
	t_list	**begin;
	t_list	*src;

	begin = &lst;
	src = *begin;
	if (!src)
		return ;
	while (src->next != NULL)
	{
		f(src, data);
		src = src->next;
	}
	f(src, data);
}
