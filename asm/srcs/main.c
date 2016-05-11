/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:48:17 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/11 17:24:32 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data	g_data;

void		global_init(void)
{
	g_data.line = 0;
	g_data.addr = 0;
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

int			main(int ac, char **av)
{
	int		fd;
	int		i;
	int		arg;
	char	*str;

	arg = 0;
	i = 1;
	global_init();
	if (ac <= 1)
		ft_exit_error(ER_EMPTY, NULL);
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-a") == 0)
			arg++;
		else
			str = av[i];
		i++;
	}
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
	parse_file(fd, change_name(str), arg);
	if (close(fd) == -1)
		ft_exit_error(ER_CLOSE, str);
	return (EXIT_SUCCESS);
}
