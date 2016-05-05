/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:48:17 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/04 13:53:35 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av)
{
	char	*line;
	int		fd;

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
	while (get_next_line(fd, &line) > 0)
		ft_printf("%s\n", line);
	if (close(fd) == -1)
		ft_exit_error(ER_CLOSE, av[ac - 1]);
	return (EXIT_SUCCESS);
}
