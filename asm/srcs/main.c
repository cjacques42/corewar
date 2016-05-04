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
	int		nb = 4294967289;

	ft_printf("\n%d\n", nb);
	if (ac <= 1)
	{
		ft_putstr_fd("Usage: ./examples/asm [-a] <sourcefile.s>\
\n    -a : Instead of creating a .cor file, outputs a stripped and \
annotated version of the code to the standard output\n", 2);
		exit(0);
	}
	if ((fd = open(av[ac - 1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Can't read source file ", 2);
		ft_putstr_fd(av[ac - 1], 2);
		ft_putstr_fd("\n", 2);
		exit (0);
	}
	while (get_next_line(fd, &line) > 0)
		ft_printf("%s\n", line);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Can't close source file ", 2);
		ft_putstr_fd(av[ac - 1], 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);
}
