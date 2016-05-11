/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:12:42 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/11 10:43:13 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_nbr(char **str, long nbr, int errno)
{
	size_t		i;
	long		total;

	(void)nbr;
	total = 0;
	i = 0;
	if ((*str)[i] == '-' || (*str)[i] == '+')
		ft_exit_mess(15);
	if (ft_isdigit((*str)[i]) == 0)
		ft_exit_mess(errno);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		total = (total * 10 + ((*str)[i] - '0')) % nbr;
		i++;
	}
	*str += i;
	return (total);
}

void			ft_addarg(t_list **args, int type, long nb, char *str)
{
	t_arg		*arg;

	if ((arg = (t_arg*)malloc(sizeof(*arg))) == NULL)
		exit(0);
	arg->type = type;
	arg->nb = nb;
	arg->str = str;
	arg->key = NULL;
	ft_lstaddback(args, ft_lstnew((void*)arg, sizeof(arg)));
}

static int		nb_reg(char **str)
{
	size_t		i;
	int			total;

	total = 0;
	i = 0;
	if ((*str)[i] == '-' || (*str)[i] == '+')
		ft_exit_mess(15);
	if (ft_isdigit((*str)[i]) == 0)
		ft_exit_mess(16);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		total = total * 10 + ((*str)[i] - '0');
		if (total < 1 || total > 16)
			ft_exit_mess(17);
		i++;
	}
	*str += i;
	return (total);
}

void			check_reg(char **line, t_list **args)
{
	int		nb;

	(*line)++;
	nb = nb_reg(line);
	ft_addarg(args, T_REG, nb, NULL);
}
