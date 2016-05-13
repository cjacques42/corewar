/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:56:56 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/13 15:15:13 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	bin_uchar_f_long(long var, int len, int fd)
{
	unsigned char	*c;
	int				i;

	i = len - 1;
	c = (unsigned char*)&var;
	while (i >= 0)
	{
		ft_putchar_fd(c[i], fd);
		i--;
	}
}

void	bin_uchar_f_int(int var, int fd)
{
	unsigned char	*c;

	c = (unsigned char*)&var;
	ft_putchar_fd(c[0], fd);
}

void	bin_uint(unsigned int nb, int fd)
{
	unsigned char	*c;

	c = (unsigned char*)&nb;
	ft_putchar_fd(c[3], fd);
	ft_putchar_fd(c[2], fd);
	ft_putchar_fd(c[1], fd);
	ft_putchar_fd(c[0], fd);
}

void	bin_str(char *str, int len, int fd)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	bin_header(t_header *header, int fd)
{
	bin_uint(header->magic, fd);
	bin_str(header->prog_name, PROG_NAME_LENGTH, fd);
	bin_uint(0, fd);
	bin_uint(header->prog_size, fd);
	bin_str(header->comment, COMMENT_LENGTH, fd);
	bin_uint(0, fd);
}
