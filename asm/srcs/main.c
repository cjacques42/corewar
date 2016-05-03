/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:48:17 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/02 12:01:16 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av)
{
	char	*line;
	int		fd;

	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("Error file name.");
		exit (0);
	}
	while (get_next_line(fd, &line) > 0)
		ft_printf("%s\n", line);
	if (close(fd) == -1)
		ft_putstr("Error closure.");
	return (0);
}
