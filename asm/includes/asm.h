/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:32:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 17:54:56 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define TRUE		1
# define FALSE		0

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
# include "../../utils/op.h"
#include "stdio.h"

typedef enum	s_error
{
		ER_OPEN,
		ER_CLOSE,
		ER_FORMAT,
		ER_EMPTY
}				t_error;

typedef struct						s_mess
{
	char							*str;
}									t_mess;

static t_mess						g_err[] =
{
	{"Bad syntax"},
	{"String is too long"},
	{"Command already used"},
	{"Bad command"},
	{"String without end"},
	{0}
};

typedef struct		s_data
{
	int		line;
}					t_data;

extern t_data		g_data;

void			ft_exit_error(t_error err, char *str);
void			start_lex(int fd);
t_header		*init_header(void);
int				ft_isspace(int c);
int				ft_comment(int c);
int				ft_empty(char *str);
void			ft_exit_mess(int errno);

#endif
