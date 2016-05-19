/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:48:17 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 12:49:19 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data	g_data;

void		global_init(void)
{
	g_data.line = 0;
	g_data.col = 1;
	g_data.addr = 0;
	g_data.cmds = NULL;
	g_data.lbls = NULL;
}

char		*change_name(char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = ft_memalloc(sizeof(*tmp) * (len + 3));
	ft_strcpy(tmp, str);
	ft_strcpy(tmp + (len - 1), "cor");
	return (tmp);
}

int			ft_count_arg(char **str, char **av, int ac)
{
	int		i;
	int		arg;

	i = 1;
	arg = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-a") == 0)
			arg++;
		else
			*str = av[i];
		i++;
	}
	return (arg);
}

int			main(int ac, char **av)
{
	int		fd;
	int		arg;
	char	*str;

	global_init();
	if (ac <= 1)
		ft_exit_error(ER_EMPTY, NULL);
	arg = ft_count_arg(&str, av, ac);
	if (ac - arg <= 1)
		ft_exit_error(ER_OPEN, "(null)");
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_exit_error(ER_OPEN, str);
	if (ft_strcmp(&str[ft_strlen(str) - 2], ".s") != 0)
	{
		if (close(fd) == -1)
			ft_exit_error(ER_CLOSE, str);
		ft_exit_error(ER_FORMAT, NULL);
	}
	str = change_name(str);
	parse_file(fd, str, arg);
	if (close(fd) == -1)
		ft_exit_error(ER_CLOSE, NULL);
	free(str);
	return (EXIT_SUCCESS);
}
