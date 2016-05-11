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

void		print_first(t_arg *arg)
{
	(void)arg;
	ft_printf("%-18s", "test");
}

void		print_second(t_arg *arg)
{
	ft_printf("\t\t\t\t\t%-4d", arg->nb - 1);
}

void		print_third(t_arg *arg)
{
	(void)arg;
}

void		print_cmd(t_cmd *cmd)
{
	t_list		*tmp;
	int			i;
	void		(*ptr_funct[3])(t_arg *);

	ptr_funct[0] = &print_first;
	ptr_funct[1] = &print_second;
	ptr_funct[2] = &print_third;
	ft_printf("%-5d(%-3d) :\t\t%-10s", cmd->addr, cmd->size, cmd->str);
	i = 0;
	while (i < 3)
	{
		tmp = cmd->arg;
		ft_printf("\t\t\t\t\t%-4d", cmd->nbr + 1);
		while (tmp != NULL)
		{
			(*ptr_funct)(tmp->content);
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
