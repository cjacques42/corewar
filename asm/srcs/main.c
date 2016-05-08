/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:48:17 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 17:40:13 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data	g_data;

void	global_init(void)
{
	g_data.line = 0;
}

int main(int ac, char **av)
{
	int		fd;

	global_init();
	if (ac <= 1)
		ft_exit_error(ER_EMPTY, NULL);
	if ((fd = open(av[ac - 1], O_RDONLY)) == -1)
		ft_exit_error(ER_OPEN, av[ac - 1]);
	if (ft_strcmp(&av[ac - 1][ft_strlen(av[ac - 1]) - 2], ".s") != 0)
	{
		if (close(fd) == -1)
			ft_exit_error(ER_CLOSE, av[ac - 1]);
		ft_exit_error(ER_FORMAT, NULL);
	}
	parse_file(fd);
	if (close(fd) == -1)
		ft_exit_error(ER_CLOSE, av[ac - 1]);
	return (EXIT_SUCCESS);
}
