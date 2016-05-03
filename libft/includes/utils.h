/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 11:30:59 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 17:06:20 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct		s_args
{
	unsigned char	val_ht;
	unsigned char	val_z;
	unsigned char	val_plus;
	unsigned char	val_minus;
	unsigned char	val_sp;
	unsigned char	val_field;
	unsigned char	val_prec;
	unsigned char	val_conv;
	int				field;
	int				precis;
	char			conv[3];
	char			type;
}					t_args;

int					ft_searchtype(char const *format, char *type);
int					ft_checktype(char const **format, va_list *list_args);
size_t				ft_nbrlen(intmax_t nbr);
size_t				ft_nbrlen_base(uintmax_t nbr, unsigned int base);
void				ft_extract_options(char const **format, t_args *arg);
int					ft_extract_field(char const **format, t_args *arg);
int					ft_extract_precis(char const **format, t_args *args);
void				ft_extract_conv(char const **format, t_args *arg);
int					ft_ft(char const *format, va_list *list_args, int nb_char);
int					ft_parse(const char **format, t_args *args);
int					ft_call_print(va_list *list_args, t_args *arg);
int					ft_retfield(t_args *arg, int ret);
void				ft_printnchar(size_t len, char c);
int					ft_checktype(const char **format, va_list *list_args);
void				ft_putbase(uintmax_t nb, unsigned int base, char type);
int					ft_print_signed(va_list *list_arg, t_args *arg);
uintmax_t			ft_cast_unsigned(va_list *list_args, t_args *arg);
int					ft_print_str(va_list *list_args, t_args *arg);
int					ft_print_wstr(va_list *list_args, t_args *arg);
int					ft_print_void(va_list *list_args, t_args *arg);
int					ft_print_unsigned(va_list *list_args, t_args *arg);
int					ft_print_hex(va_list *list_args, t_args *arg);
int					ft_print_oct(va_list *list_args, t_args *arg);
int					ft_print_char(va_list *list_args, t_args *arg);
int					ft_print_wchar(va_list *list_args, t_args *arg);
int					ft_print_percent(va_list *list_args, t_args *arg);

#endif
