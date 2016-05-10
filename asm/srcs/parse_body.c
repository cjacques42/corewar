/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:42:50 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/10 17:56:37 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_lbl(char *line, t_list **cmds, t_list **lbls)
{
	int		i;
	t_lbl	*label;

	i = 0;
	while (ft_strchr(LABEL_CHARS, line[i]) != NULL)
		i++;
	if (line[i] == LABEL_CHAR)
	{
		if ((label = (t_lbl*)malloc(sizeof(*label))) == NULL)
			exit(0);
		label->lbl_name = ft_strsub(line, 0, i);
		label->adress = g_data.addr;
		ft_lstaddback(lbls, ft_lstnew((void*)label, sizeof(label)));
		line = ft_strtrim(line + i + 1);
		if (ft_empty(line) == 1)
			return (1);
		return (check_line(line, cmds, lbls));
	}
	return (0);
}

//int		ft_size(t_list *cmds)
//{
	//
//}

void	parse_body(int fd)
{
	char	*line;
	t_list	*lbls;
	t_list	*cmds;
	int		ret_line;
	int		ret_lbl;

	lbls = NULL;
	cmds = NULL;
	while (read_line(fd, &line) > 0)
	{
		ret_line = check_line(line, &cmds, &lbls);
		ret_lbl = check_lbl(line, &cmds, &lbls);
		if (ft_empty(line) == 0 && ret_lbl == 0 && ret_line == 0)
			ft_exit_mess(8);
//		ft_size(cmds);
		free(line);
	}
}
