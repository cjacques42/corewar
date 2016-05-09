/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:42:50 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/09 17:39:14 by cjacques         ###   ########.fr       */
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

void	parse_body(int fd)
{
	char	*line;
	t_list	*lbls;
	t_list	*cmds;

	lbls = NULL;
	cmds = NULL;
	while (read_line(fd, &line) > 0)
	{
		if (check_line(line, &cmds, &lbls) == 1)
			printf("MNEMO\n");
		else if (check_lbl(line, &cmds, &lbls) == 1)
			printf("LABEL\n");
		else if (ft_empty(line) == 0)
			ft_exit_mess(0);
		printf("-- %s\n", line);
		free(line);
	}
}
