/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:28:19 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 19:30:41 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lstiter(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	**begin;
	t_list	*src;

	begin = &lst;
	src = *begin;
	if (!src)
		return ;
	while (src->next != NULL)
	{
		src = f(src);
	}
	f(src);
}

int		change_carry(int val)
{
	if (val == 0)
		return (1);
	else
		return (0);
}
