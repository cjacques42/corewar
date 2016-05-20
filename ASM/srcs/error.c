/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:12 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 19:37:49 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_lexixal_error(void)
{
	ft_printf("Lexical error at [%d:%d]\n", g_data.line, g_data.col);
	ft_lstdel(g_data.lbls, free_lbl);
	ft_lstdel(g_data.cmds, free_cmd);
	free(g_data.str);
	exit(0);
}

void		ft_tok_error(t_token tok, void *s1, void *s2, int errno)
{
	if (s1)
		g_data.col -= ft_strlen(s1);
	if (errno == 0)
	{
		if (tok == ENDLINE)
			ft_printf(g_err[2].str, g_data.line, g_data.col, g_tok[tok].str);
		else
			ft_printf(g_err[0].str, g_data.line, g_data.col, g_tok[tok].str
					, s1);
	}
	else if (errno == 1)
		ft_printf(g_err[1].str, s2, g_data.line, g_data.col, g_tok[tok].str
				, s1);
	else if (errno == 2)
		ft_printf(g_err[3].str, s1);
	else if (errno == 3)
		ft_printf(g_err[4].str, s1);
	free(s1);
	free(*(g_data.tmp));
	free(g_data.str);
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

void		ft_head_error(int len, t_header *header, char *str)
{
	ft_puterr("Champion ");
	ft_puterr(str);
	ft_puterr(" too long (Max length ");
	ft_putnbr_fd(len, 2);
	ft_puterr(")\n");
	free(header);
	exit(0);
}
