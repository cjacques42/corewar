/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:09:46 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/11 19:24:12 by cjacques         ###   ########.fr       */
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
			ft_printf("%-4d%-4d%-4d%-6d", octet[3], octet[2], octet[1], octet[0]);
		else
			ft_printf("%-4d%-14d", octet[1], octet[0]);
	}
	else
		ft_printf("%-4d%-14d", octet[1], octet[0]);
}

void		print_third(t_arg *arg, int opc)
{
	(void)opc;
	ft_printf("%-18d", arg->nb);
}

void		add_key(t_arg *arg)
{
	char	*prefix;

	prefix = NULL;
	if (arg->type == T_REG)
		prefix = ft_strdup("r");
	else if (arg->type == T_DIR && arg->str != NULL)
		prefix = ft_strdup("%:");
	else if (arg->type == T_DIR)
		prefix = ft_strdup("%");
	else if (arg->type == T_IND && arg->str != NULL)
		prefix = ft_strdup(":");
	if (prefix == NULL)
		arg->key = ft_itoa((int)arg->nb);
	else if (arg->str == NULL)
		arg->key = ft_strjoin(prefix, ft_itoa((int)arg->nb));
	else
		arg->key = ft_strjoin(prefix, arg->str);
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
			add_key(tmp->content);
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
		if (cmds != NULL)
			addr_cmd = ((t_cmd*)(cmds->content))->addr;
		if (lbls != NULL)
			addr_lbl = ((t_lbl*)(lbls->content))->adress;
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
