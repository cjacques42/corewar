/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:11:39 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/12 11:11:47 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_dir(char **line, t_list **args, t_list **cmds)
{
	t_arg	*arg;
	t_list	*tmp;
	int		index;

	index = 1;
	tmp = *cmds;
	while (tmp->next != NULL)
		tmp = tmp->next;
	arg = ft_addarg(args, T_DIR);
	ft_search(line, tmp, arg, index);
}
