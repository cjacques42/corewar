/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:09:03 by cjacques          #+#    #+#             */
/*   Updated: 2015/12/02 14:17:20 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*final;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	final = ft_lstnew(lst->content, lst->content_size);
	if (final == NULL)
		return (NULL);
	final->content = f(lst)->content;
	final->content_size = f(lst)->content_size;
	tmp = final;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new->content = f(lst)->content;
		new->content_size = f(lst)->content_size;
		tmp->next = new;
		lst = lst->next;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (final);
}
