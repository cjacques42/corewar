/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:59:43 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/13 18:12:17 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_add_args_to_cmd(t_list **cmds, t_list *args)
{
	t_list	*tmp;

	tmp = *cmds;
	while (tmp->next != NULL)
		tmp = tmp->next;
	((t_cmd*)(tmp)->content)->arg = args;
}

int		ft_check_type(t_list *cmd, int opc, t_list *arg, int nb)
{
	int		type_arg;
	int		type_op;
	int		size;

	type_arg = ((t_arg*)(arg->content))->type;
	type_op = g_op_tab[opc].type[nb];
	if (!(type_op & type_arg))
		return (0);
	if (type_arg == T_DIR)
	{
		if (g_op_tab[opc].dir_size == 1)
			size = 2;
		else
			size = 4;
	}
	if (type_arg == T_IND)
		size = 2;
	if (type_arg == T_REG)
		size = 1;
	((t_cmd*)(cmd)->content)->size += size;
	return (1);
}

int		ft_count(t_list *cmd)
{
	t_list	*arg;
	int		i;
	int		index;

	i = 0;
	while (cmd->next != NULL)
		cmd = cmd->next;
	index = ((t_cmd*)(cmd)->content)->nbr;
	arg = ((t_cmd*)(cmd)->content)->arg;
	while (arg != NULL)
	{
		if (g_op_tab[index].nb_arg <= i)
			ft_exit_mess(18);
		if (ft_check_type(cmd, index, arg, i) != 1)
			ft_exit_mess(20);
		arg = arg->next;
		i++;
	}
	if (g_op_tab[index].ocp == 0)
		((t_cmd*)(cmd)->content)->size++;
	g_data.addr += ((t_cmd*)(cmd)->content)->size;
	if (g_op_tab[index].nb_arg > i)
		ft_exit_mess(19);
	return (0);
}
