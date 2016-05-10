/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:41:28 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/10 17:21:12 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list		*lst;

	lst = *alst;
	if (new == NULL || alst == NULL)
		return ;
	if (lst != NULL)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		new->previous = lst;
	}
	else
		*alst = new;
}
