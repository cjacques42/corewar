/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:32:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 17:40:14 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

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

void			ft_exit_error(t_error err, char *str);
void			start_lex(int fd);
t_header		*init_header(void);
int				ft_isspace(int c);

#endif
