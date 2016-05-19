/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:32:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 10:01:55 by cjacques         ###   ########.fr       */
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
	t_token		token;
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
	{"LABEL"},
	{"DIRECT"},
	{"DIRECT_LABEL"},
	{"REGISTER"},
	{"INDIRECT_LABEL"},
	{"INDIRECT"},
	{"ENDLINE"},
	{"END"},
	{"COMMAND_NAME"},
	{"COMMAND_COMMENT"},
	{"STRING"},
	{"SEPARATOR"},
	{"INSTRUCTION"},
	{0}
};

typedef struct		s_data
{
	int			line;
	int			col;
	int			addr;
	int			fd;
	char		**str;
	t_header	**header;
	t_list		**cmds;
	t_list		**lbls;
}					t_data;

extern t_data		g_data;

t_token				next_token(int fd, char **str);

void				parse_file(int fd, char *str, int arg);
void				ft_body(int fd, t_header *header, t_list **lbls
		, t_list **cmds);
t_cmd				*ft_cmd(int fd, t_list **cmds, char *str);
int                 ft_arg(t_cmd *cmd, int index, t_token tok, char *str);
int					ft_dir(t_token tok, t_cmd *cmd, t_arg *arg);
int					ft_ind(t_token tok, t_cmd *cmd, t_arg *arg);
int					ft_reg(t_token tok, t_arg *arg);
int					ft_search(t_cmd *cmd, t_arg *arg, t_token tok, int index);
int					check_nbr(char *str, long nbr, int index);

char				*ft_beg_trim(char *str);
char				*ft_freejoin(char *s1, char *s2, int arg1, int arg2);
int					read_line(int fd, char **tmp, char **line);
int					ft_isspace(int c);
int					ft_comment(int c);

void				ft_exit_error(t_error err, char *str);
void				ft_tok_error(t_token tok, char *s1, char *s2, int errno);
void				ft_lexixal_error(void);

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

#endif
