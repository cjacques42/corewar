/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:32:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/17 12:21:30 by cjacques         ###   ########.fr       */
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

typedef enum		e_error
{
	ER_OPEN, ER_CLOSE, ER_FORMAT, ER_EMPTY, ER_WRITE
}					t_error;

typedef enum		e_token
{
	LABEL,
	DIRECT,
	DIRECT_LABEL,
	REGISTER,
	INDIRECT_LABEL,
	INDIRECT,
	ENDLINE,
	END,
	COMMAND_NAME,
	COMMAND_COMMENT,
	STRING,
	SEPARATOR,
	INSTRUCTION,
	NONE
}					t_token;

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
	char		*key;
	int			type;
	long		nb;
	char		*str;
}					t_arg;

typedef struct		s_cmd
{
	char		*str;
	int			addr;
	int			size;
	int			opc;
	int			nbr;
	t_list		*arg;
	int			line;
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
	{"Any sign"},
	{"Any number"},
	{"registry number not beetween 1 and 16"},
	{"Too much parameter"},
	{"Too few parameter"},
	{"Wrong Type"},
	{0}
};

typedef struct		s_data
{
	int			line;
	int			addr;
	int			fd;
}					t_data;

extern t_data		g_data;

t_header			*init_header(void);
void				ft_add_args_to_cmd(t_list **cmds, t_list *args);
t_arg				*ft_addarg(t_list **args, int type);
int					ft_count(t_list *cmd);
int					read_line(int fd, char **line);
void				parse_file(int fd, char *str, int arg);
void				parse_body(int fd, t_header *header, t_list **lbls
		, t_list **cmds);

int					ft_isspace(int c);
int					ft_comment(int c);
int					ft_empty(char *str);

void				ft_exit_mess(int errno);
void				ft_exit_error(t_error err, char *str);

void				check_eol(char *line);
int					check_line(char *line, t_list **cmds, t_list **lbls);
void				check_reg(char **line, t_list **args);
void				check_dir(char **line, t_list **args, t_list **cmds);
void				check_ind(char **line, t_list **args, t_list **cmds);
int					check_nbr(char **str, long nbr, int errno, int *index);
int					ft_search(char **line, t_list *cmd, t_arg *arg, int index);
void				print_information(t_header *header, t_list *lbls
		, t_list *cmds);

void				binary(t_header *header, t_list *cmds, char *str);
void				bin_header(t_header *header, int fd);
void				bin_str(char *str, int len, int fd);
void				bin_uint(unsigned int nb, int fd);
void				bin_uchar_f_int(int var, int fd);
void				bin_uchar_f_long(long var, int len, int fd);

void				free_header(t_header *header);
void				free_cmd(void *cmds, size_t size);
void				free_lbl(void *lbls, size_t size);

t_token				next_token(int fd, char **str);
char				*ft_beg_trim(char *str);
int					ft_separator(char c);

#endif
