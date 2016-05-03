/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:20:30 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/15 18:04:06 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*src;

	if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		src = *alst;
		while (src->next != NULL)
			src = src->next;
		src->next = new;
	}
}
