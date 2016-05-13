/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:42:50 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/13 19:06:52 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_lbl(char *line, t_list **cmds, t_list **lbls)
{
	int		i;
	int		ret;
	t_lbl	*label;

	i = 0;
	label = NULL;
	while (line[i] && ft_strchr(LABEL_CHARS, line[i]) != NULL)
		i++;
	if (i != 0 && line[i] == LABEL_CHAR)
	{
		if ((label = (t_lbl*)malloc(sizeof(*label))) == NULL)
			exit(0);
		label->lbl_name = ft_strsub(line, 0, i);
		label->adress = g_data.addr;
		ft_lstaddback(lbls, ft_lstnew((void*)label, sizeof(label)));
		line = ft_strtrim(line + i + 1);
		if (ft_empty(line) == 1)
			ret = 1;
		else
			ret = check_line(line, cmds, lbls);
		free(line);
		return (ret);
	}
	return (0);
}

int		ft_lbl_exist(t_list *lbls, char *str)
{
	t_lbl	*tmp;

	while (lbls != NULL)
	{
		tmp = lbls->content;
		if (ft_strcmp(str, tmp->lbl_name) == 0)
			return (tmp->adress);
		lbls = lbls->next;
	}
	ft_exit_mess(11);
	return (-1);
}

void	ft_opc(t_cmd *cmd, t_arg *arg, int decal)
{
	unsigned char		reg;
	unsigned char		dir;
	unsigned char		ind;

	reg = 0x01;
	dir = 0x02;
	ind = 0x03;
	if (arg->type == T_REG)
		cmd->opc = cmd->opc | (reg << decal);
	if (arg->type == T_DIR)
		cmd->opc = cmd->opc | (dir << decal);
	if (arg->type == T_IND)
		cmd->opc = cmd->opc | (ind << decal);
}

void	ft_refresh_lbl_addr(t_list *lbls, t_list *cmds)
{
	t_list	*tmp;
	t_arg	*arg;
	int		addr_cur;
	int		i;

	while (cmds != NULL)
	{
		i = 6;
		tmp = ((t_cmd*)(cmds->content))->arg;
		while (tmp != NULL)
		{
			arg = tmp->content;
			ft_opc(((t_cmd*)(cmds->content)), arg, i);
			if (arg->str != NULL)
			{
				addr_cur = ((t_cmd*)(cmds->content))->addr;
				g_data.line = ((t_cmd*)(cmds->content))->line;
				arg->nb = ft_lbl_exist(lbls, arg->str) - addr_cur;
			}
			i -= 2;
			tmp = tmp->next;
		}
		cmds = cmds->next;
	}
}

void	parse_body(int fd, t_header *header, t_list **lbls, t_list **cmds)
{
	char	*line;
	int		ret_line;
	int		ret_lbl;

	line = NULL;
	while (read_line(fd, &line) > 0)
	{
		ret_line = check_line(line, cmds, lbls);
		ret_lbl = check_lbl(line, cmds, lbls);
		if (ft_empty(line) == 0 && ret_lbl == 0 && ret_line == 0)
			ft_exit_mess(8);
		free(line);
	}
	ft_refresh_lbl_addr(*lbls, *cmds);
	header->prog_size = g_data.addr;
}
