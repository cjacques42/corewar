/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:51:25 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/27 14:39:48 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm(t_list **alst, t_list *elem)
{
	t_list	*src;
	int		i;

	i = 0;
	if ((*alst) == NULL)
		return ;
	src = *alst;
	while (src->next != NULL && i < 5000)
	{
		if (src->next->content == elem->content)
			src->next = src->next->next;
		src = src->next;
		if (src == NULL)
			break ;
		i++;
	}
}
