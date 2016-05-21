/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:09:46 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/16 14:41:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_first(t_arg *arg, int opc)
{

	(void)opc;
	ft_printf("%-18s", arg->key);
}

void		print_second(t_arg *arg, int opc)
{
	unsigned char	*octet;

	octet = (unsigned char*)&arg->nb;
	if (arg->type == T_REG)
		ft_printf("%-18d", arg->nb);
	else if (arg->type == T_DIR)
	{
		if (g_op_tab[opc].dir_size == 0)
			ft_printf("%-4d%-4d%-4d%-6d", octet[3], octet[2], octet[1]
					, octet[0]);
		else
			ft_printf("%-4d%-14d", octet[1], octet[0]);
	}
	else
		ft_printf("%-4d%-14d", octet[1], octet[0]);
}

void		print_third(t_arg *arg, int opc)
{
	int		i;

	i = 0;
	(void)opc;
	if (arg->str != NULL || arg->type == T_REG)
		ft_printf("%-18d", arg->nb);
	else
	{
		while (arg->key[i] && !ft_isdigit(arg->key[i]) && arg->key[i] != '-')
			i++;
		ft_printf("%-18d", ft_atoi(arg->key + i));
	}
}

void		print_cmd(t_cmd *cmd)
{
	t_list		*tmp;
	int			i;
	void		(*ptr_funct[3])(t_arg *, int opc);

	ptr_funct[0] = &print_first;
	ptr_funct[1] = &print_second;
	ptr_funct[2] = &print_third;
	ft_printf("%-5d(%-3d) :        %-10s", cmd->addr, cmd->size, cmd->str);
	i = 0;
	while (i < 3)
	{
		tmp = cmd->arg;
		if (i > 0 && g_op_tab[cmd->nbr].ocp == 1)
			ft_printf("                    %-10d", cmd->nbr + 1);
		else if (i > 0)
			ft_printf("                    %-4d%-6d", cmd->nbr + 1, cmd->opc);
		while (tmp != NULL)
		{
			(*ptr_funct[i])(tmp->content, cmd->nbr);
			tmp = tmp->next;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void		print_information(t_header *header, t_list *lbls, t_list *cmds)
{
	int		addr_cmd;
	int		addr_lbl;
	t_lbl	*lbl;

	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", header->prog_size);
	ft_printf("Name : \"%s\"\n", header->prog_name);
	ft_printf("Comment : \"%s\"\n\n", header->comment);
	while (lbls != NULL || cmds != NULL)
	{
		addr_cmd = (cmds != NULL) ? ((t_cmd*)(cmds->content))->addr : 0;
		addr_lbl = (lbls != NULL) ? ((t_lbl*)(lbls->content))->adress : 0;
		if (lbls != NULL && (cmds == NULL || addr_lbl <= addr_cmd))
		{
			lbl = ((t_lbl*)(lbls->content));
			ft_printf("%-11d:    %s:\n", lbl->adress, lbl->lbl_name);
			lbls = lbls->next;
		}
		else if (cmds != NULL && (lbls == NULL || addr_lbl > addr_cmd))
		{
			print_cmd(cmds->content);
			cmds = cmds->next;
		}
	}
}
