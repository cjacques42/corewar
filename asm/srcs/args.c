/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:59:43 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/10 13:28:23 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_add_args_to_cmd(t_list **cmds, t_list *args)
{
	while ((*cmds)->next != NULL)
		(*cmds) = (*cmds)->next;
	((t_cmd*)(*cmds)->content)->arg = args;
}
