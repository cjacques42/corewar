/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:12 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 11:21:02 by cjacques         ###   ########.fr       */
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
	free_header(*(g_data.header));
	ft_lstdel(g_data.lbls, free_lbl);
	ft_lstdel(g_data.cmds, free_cmd);
	exit(0);
}

void		ft_tok_error(t_token tok, char *s1, char *s2, int errno)
{
	if (errno == 0)
		ft_puterr("Syntax error at");
	else if (errno == 1)
		ft_printf("No such label %s while attempting to dereference", s2);
	else
		ft_puterr("Invalid instruction at");
	ft_puterr(" token [TOKEN][");
	ft_printf("%03d", g_data.line);
	ft_puterr(":");
	ft_printf("%03d", g_data.col);
	ft_puterr("]");
	if (tok != ENDLINE)
	{
		ft_puterr(" ");
		ft_puterr(g_err[tok].str);
		ft_puterr(" \"");
		ft_puterr(s1);
		ft_puterr("\"");
	}
	ft_puterr("\n");
	free(s1);
	free_header(*(g_data.header));
	ft_lstdel(g_data.lbls, free_lbl);
	ft_lstdel(g_data.cmds, free_cmd);
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

void		ft_head_error(int len, t_header *header)
{
	ft_puterr("Champion name too long (MAX length ");
	ft_putnbr_fd(len, 2);
	ft_puterr(")\n");
	free(header);
	exit(0);
}
