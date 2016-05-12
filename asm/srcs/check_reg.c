/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:12:42 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/12 14:20:42 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static int		nb_reg(char **str, char **key)
{
	size_t		i;
	int			total;

	total = 0;
	i = 1;
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
	*key = ft_strsub(*str, 0, i);
	*str += i;
	return (total);
}

void			check_reg(char **line, t_list **args)
{
	t_arg	*arg;
	char	*key;

	key = NULL;
	arg = ft_addarg(args, T_REG);
	arg->nb = nb_reg(line, &key);
	arg->key = key;
}
