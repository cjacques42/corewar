/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:14 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 17:58:50 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_lbl_exist(t_list *lbls, t_arg *arg)
{
	t_lbl	*tmp;

	while (lbls != NULL)
	{
		tmp = lbls->content;
		if (ft_strcmp(arg->str, tmp->lbl_name) == 0)
			return (tmp->adress);
		lbls = lbls->next;
	}
	ft_tok_error(arg->token, ft_strdup(arg->key), arg->str, 1);
	return (0);
}

static void		ft_opc(t_cmd *cmd, t_arg *arg, int decal)
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

static void		ft_refresh_lbl_addr(t_list *lbls, t_list *cmds)
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
				g_data.col = arg->col;
				arg->nb = ft_lbl_exist(lbls, arg) - addr_cur;
			}
			i -= 2;
			tmp = tmp->next;
		}
		cmds = cmds->next;
	}
}

static int		ft_lbl(t_list **lbls, char *str)
{
	t_lbl	*label;

	label = NULL;
	if ((label = (t_lbl*)malloc(sizeof(*label))) == NULL)
		return (0);
	str[ft_strlen(str) - 1] = 0;
	label->lbl_name = str;
	label->adress = g_data.addr;
	ft_lstaddback(lbls, ft_lstnew((void*)label, sizeof(label)));
	return (1);
}

void			ft_body(int fd, t_header *header, t_list **lbls, t_list **cmds)
{
	char		*str;
	t_token		tok;
	int			state;
	t_cmd		*cmd;

	state = 0;
	while ((tok = next_token(fd, &str)) != END)
		if (state == 0 && tok == LABEL)
		{
			ft_lbl(lbls, str);
			state++;
		}
		else if (tok == INSTRUCTION)
		{
			cmd = ft_cmd(fd, cmds, str);
			state = 0;
		}
		else if (tok != ENDLINE)
			ft_tok_error(tok, str, NULL, 0);
		else
			state = 0;
	free(str);
	ft_refresh_lbl_addr(*lbls, *cmds);
	header->prog_size = g_data.addr;
}
