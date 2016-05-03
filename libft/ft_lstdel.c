/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:53:02 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/05 14:39:06 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*src;

	src = *alst;
	del(src->content, src->content_size);
	if (src->next != NULL)
		ft_lstdel(&src->next, del);
	free(src);
	*alst = NULL;
}
