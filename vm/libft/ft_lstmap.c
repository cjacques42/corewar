/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:04:21 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 22:00:36 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*ret;

	if (!lst)
		return (NULL);
	result = f(lst);
	ret = result;
	while (lst->next != NULL)
	{
		result->next = f(lst->next);
		lst = lst->next;
		result = result->next;
	}
	return (ret);
}
