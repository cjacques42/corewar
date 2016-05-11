/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:13:28 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/11 10:01:08 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_search(char **line, t_list **cmds, long *nb, char **str)
{
	int		i;
	t_list	*tmp;

	tmp = *cmds;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = ((t_cmd*)(tmp)->content)->nbr;
	if (ft_isdigit(**line) == 1)
	{
		if (g_op_tab[i].dir_size == 1)
			*nb = check_nbr(line, 65536, 0);
		else
			*nb = check_nbr(line, 4294967296, 0);
		printf("%ld ", *nb);
	}
	else
	{
		(*line)++;
		i = 0;
		while (ft_strchr(LABEL_CHARS, (*line)[i]) != NULL && (*line)[i])
			i++;
		*str = ft_strsub(*line, 0, i);
		if (ft_isspace((*line)[i]) == 0 && ft_comment((*line)[i]) == 0 &&
				(*line)[i] != SEPARATOR_CHAR && (*line)[i] != 0)
			ft_exit_mess(10);
		*line += i;
		printf("%s ", *str);
	}
	return (0);
}

void		check_ind(char **line, t_list **args, t_list **cmds)
{
	char	*str;
	long	nb;

	nb = -1;
	str = NULL;
	ft_search(line, cmds, &nb, &str);
	ft_addarg(args, T_IND, nb, str);
	printf("Ind - ");
}
