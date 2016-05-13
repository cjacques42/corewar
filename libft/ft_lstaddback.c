/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:41:28 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/13 15:32:47 by cjacques         ###   ########.fr       */
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
		(*alst)->previous->next = new;
		new->previous = (*alst)->previous;
	}
	else
		*alst = new;
	(*alst)->previous = new;
}
