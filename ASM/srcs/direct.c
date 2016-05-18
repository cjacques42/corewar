/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:34 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/18 17:50:31 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
int				check_nbr(char **str, long nbr, int errno, int *index)
{
	size_t		i;
	long		total;
	int			neg;

	total = 0;
	i = *index;
	neg = 1;
	if ((*str)[i] == '-')
	{
		i++;
		neg = -1;
	}
	if ((*str)[i] == '+')
		ft_exit_mess(15);
	if (ft_isdigit((*str)[i]) == 0)
		ft_exit_mess(errno);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		total = (total * 10 + ((*str)[i] - '0')) % nbr;
		i++;
	}
	*index = i;
	return (neg * total);
}

t_arg			*ft_addarg(t_list **args, int type)
{
	t_arg		*arg;

	if ((arg = (t_arg*)malloc(sizeof(*arg))) == NULL)
		exit(0);
	arg->type = type;
	arg->nb = 0;
	arg->str = NULL;
	arg->key = NULL;
	ft_lstaddback(args, ft_lstnew((void*)arg, sizeof(arg)));
	return (arg);
}
*/

void		check_dir(char **line, t_list **args, t_list **cmds)
{
	t_arg	*arg;
	t_list	*tmp;
	int		index;

	index = 1;
	tmp = *cmds;
	while (tmp->next != NULL)
		tmp = tmp->next;
	arg = ft_addarg(args, T_DIR);
	ft_search(line, tmp, arg, index);
}
