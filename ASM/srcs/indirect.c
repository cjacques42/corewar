/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:54 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/18 17:00:55 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_search(char **line, t_list *cmd, t_arg *arg, int index)
{
	int		i;

	i = ((t_cmd*)(cmd)->content)->nbr;
	if (ft_isdigit((*line)[index]) == 1 || (*line)[index] == '-')
	{
		if (g_op_tab[i].dir_size == 1)
			arg->nb = check_nbr(line, 65536, 0, &index);
		else
			arg->nb = check_nbr(line, 4294967296, 0, &index);
	}
	else
	{
		index++;
		i = index;
		while (ft_strchr(LABEL_CHARS, (*line)[index]) != NULL && (*line)[index])
			index++;
		arg->str = ft_strsub(*line, i, index - i);
		if (ft_isspace((*line)[index]) == 0 && ft_comment((*line)[index]) == 0
				&& (*line)[index] != SEPARATOR_CHAR && (*line)[index] != 0)
			ft_exit_mess(10);
	}
	arg->key = ft_strsub(*line, 0, index);
	*line += index;
	return (0);
}

void		check_ind(char **line, t_list **args, t_list **cmds)
{
	t_arg	*arg;
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = *cmds;
	while (tmp->next != NULL)
		tmp = tmp->next;
	arg = ft_addarg(args, T_IND);
	ft_search(line, tmp, arg, index);
}
