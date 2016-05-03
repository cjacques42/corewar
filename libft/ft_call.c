/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:26:03 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 17:11:25 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			ft_call_print(va_list *list_args, t_args *arg)
{
	int		(*ptr_funct)(va_list *, t_args *);

	ptr_funct = NULL;
	(arg->type == 's') ? ptr_funct = &ft_print_str : NULL;
	(arg->type == 'S') ? ptr_funct = &ft_print_wstr : NULL;
	(arg->type == 'p') ? ptr_funct = &ft_print_void : NULL;
	(arg->type == 'd') ? ptr_funct = &ft_print_signed : NULL;
	(arg->type == 'D') ? ptr_funct = &ft_print_signed : NULL;
	(arg->type == 'i') ? ptr_funct = &ft_print_signed : NULL;
	(arg->type == 'o') ? ptr_funct = &ft_print_oct : NULL;
	(arg->type == 'O') ? ptr_funct = &ft_print_oct : NULL;
	(arg->type == 'u') ? ptr_funct = &ft_print_unsigned : NULL;
	(arg->type == 'U') ? ptr_funct = &ft_print_unsigned : NULL;
	(arg->type == 'x') ? ptr_funct = &ft_print_hex : NULL;
	(arg->type == 'X') ? ptr_funct = &ft_print_hex : NULL;
	(arg->type == 'c') ? ptr_funct = &ft_print_char : NULL;
	(arg->type == 'C') ? ptr_funct = &ft_print_wchar : NULL;
	(arg->type == '%') ? ptr_funct = &ft_print_percent : NULL;
	return ((*ptr_funct)(list_args, arg));
}
