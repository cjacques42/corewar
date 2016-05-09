/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:32:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/09 18:33:29 by cjacques         ###   ########.fr       */
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

typedef enum		s_error
{
				ER_OPEN,
				ER_CLOSE,
				ER_FORMAT,
				ER_EMPTY
}					t_error;

typedef enum		s_type
{
				REG,
				DIR,
				IND
}					t_type;

typedef struct		s_mess
{
	char		*str;
}					t_mess;

typedef struct		s_lbl
{
	char		*lbl_name;
	int			adress;
}					t_lbl;

typedef struct		s_arg
{
	t_type		type;
}					t_arg;

typedef struct		s_cmd
{
	char		*str;
	int			addr;
	int			size;
	int			nbr;
	t_list		*arg;
}					t_cmd;

static t_mess		g_err[] =
{
	{"Bad syntax"},
	{"String is too long"},
	{"Header command already used"},
	{"Bad header command"},
	{"String without endif, symbol '\"' is missing"},
	{"Bad registry syntax"},
	{"Bad Direct syntax"},
	{"Bad Indirect syntax"},
	{"Command not found"},
	{"Bad syntax at the end of line"},
	{"Invalid label"},
	{"Label not found"},
	{"Selector missing"},
	{"Too much separator"},
	{"Invalid parameter"},
	{0}
};

typedef struct		s_data
{
	int			line;
	int			addr;
}					t_data;

extern t_data		g_data;

void				ft_exit_error(t_error err, char *str);
void				parse_file(int fd);
t_header			*init_header(void);
int					ft_isspace(int c);
int					ft_comment(int c);
int					ft_empty(char *str);
void				ft_exit_mess(int errno);
void				parse_body(int fd);
int					read_line(int fd, char **line);
void				check_eol(char *line);
int					check_line(char *line, t_list **cmds, t_list **lbls);
char				*check_reg(char *line, t_list **args);
char				*check_dir(char *line, t_list **args);
char				*check_ind(char *line, t_list **args);
void				ft_add_args_to_cmd(t_list **cmds, t_list *args);

#endif
