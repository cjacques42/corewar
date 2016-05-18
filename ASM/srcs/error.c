/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:12 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/18 16:17:21 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_lexixal_error(void)
{
	ft_puterr("Lexical error at [");
	ft_printf("%03d", g_data.line);
	ft_puterr(":");
	ft_printf("%03d", g_data.col);
	ft_puterr("]\n");
	exit(0);
}

void		ft_tok_error(t_token tok, char *str)
{
	ft_puterr("Syntax error at token [TOKEN][");
	ft_printf("%03d", g_data.line);
	ft_puterr(":");
	ft_printf("%03d", g_data.col);
	ft_puterr("]");
	if (tok != ENDLINE)
	{
		ft_puterr(" ");
		ft_puterr(g_err[tok].str);
		ft_puterr(" \"");
		ft_puterr(str);
		ft_puterr("\"");
	}
	ft_puterr("\n");
	exit(0);
}

void		ft_exit_error(t_error err, char *str)
{
	if (err == ER_OPEN)
	{
		ft_puterr("Can't read source file ");
		ft_puterr(str);
	}
	else if (err == ER_WRITE)
	{
		ft_puterr("Can't write source file ");
		ft_puterr(str);
	}
	else if (err == ER_CLOSE)
		ft_puterr("Can't close source file");
	else if (err == ER_FORMAT)
		ft_puterr("Can't open this file, extention isn't .s");
	else if (err == ER_EMPTY)
	{
		ft_puterr("Usage: ./examples/asm [-a] <sourcefile.s>\n    -a : ");
		ft_puterr("Instead of creating a .cor file, outputs a stripped");
		ft_puterr("and annotated version of the code to the standard output\n");
	}
	ft_puterr("\n");
	exit(1);
}

void		ft_exit_mess(int errno)
{
	ft_puterr("Error at line ");
	ft_putnbr_fd(g_data.line, 2);
	ft_puterr(": ");
	ft_puterr(g_err[errno].str);
	ft_puterr("\n");
	exit(1);
}
