/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:08:18 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/13 15:54:16 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		bin_arg(t_list *lst_arg, void *data)
{
	t_arg	*arg;
	t_cmd	*cmd;
	int		fd;

	cmd = data;
	fd = g_data.fd;
	arg = lst_arg->content;
	if (arg->type == T_REG)
		bin_uchar_f_long(arg->nb, 1, fd);
	else if (arg->type == T_DIR)
	{
		if (g_op_tab[cmd->nbr].dir_size == 0)
			bin_uchar_f_long(arg->nb, 4, fd);
		else
			bin_uchar_f_long(arg->nb, 2, fd);
	}
	else
		bin_uchar_f_long(arg->nb, 2, fd);
}

void		bin_cmd(t_list *lst_cmd)
{
	t_cmd	*cmd;
	int		fd;

	fd = g_data.fd;
	cmd = lst_cmd->content;
	bin_uchar_f_int(cmd->nbr + 1, fd);
	if (g_op_tab[cmd->nbr].ocp == 0)
		bin_uchar_f_int(cmd->opc, fd);
	ft_lstloop(cmd->arg, cmd, bin_arg);
}

void		binary(t_header *header, t_list *cmds, char *str)
{
	int		fd;

	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_exit_error(ER_WRITE, str);
	g_data.fd = fd;
	ft_printf("Writing output program to %s\n", str);
	bin_header(header, fd);
	ft_lstiter(cmds, bin_cmd);
	if (close(fd) == -1)
		ft_exit_error(ER_CLOSE, NULL);
}
