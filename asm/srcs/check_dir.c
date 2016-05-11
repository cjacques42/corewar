/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:11:39 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/11 10:00:57 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_dir(char **line, t_list **args, t_list **cmds)
{
	char	*str;
	long	nb;

	nb = -1;
	str = NULL;
	(*line)++;
	ft_search(line, cmds, &nb, &str);
	ft_addarg(args, T_DIR, nb, str);
}
