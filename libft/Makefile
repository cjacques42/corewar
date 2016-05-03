# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:02:34 by cjacques          #+#    #+#              #
#    Updated: 2016/05/02 14:55:32 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = BASH
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ_PATH = obj/
SRC_PATH =
SRC_NAME =	ft_memset.c				\
			ft_bzero.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strlen.c				\
			ft_strdup.c				\
			ft_strcpy.c				\
			ft_strncpy.c			\
			ft_strcat.c				\
			ft_strncat.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strnstr.c			\
			ft_strcmp.c				\
			ft_strncmp.c			\
			ft_atoi.c				\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_strnew.c				\
			ft_strdel.c				\
			ft_strclr.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strequ.c				\
			ft_strnequ.c			\
			ft_strsub.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_strsplit.c			\
			ft_itoa.c				\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putendl.c			\
			ft_putnbr.c				\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putwchar.c			\
			ft_putwchar_fd.c		\
			ft_putwstr.c			\
			ft_putwstr_fd.c			\
			ft_wstrlen.c			\
			ft_wcharlen.c			\
			ft_strtok.c				\
			get_next_line.c			\
			ft_call.c				\
			ft_cast_unsigned.c		\
			ft_extract.c			\
			ft_nbrlen.c				\
			ft_print_char.c			\
			ft_print_hex.c			\
			ft_print_oct.c			\
			ft_print_percent.c		\
			ft_print_signed.c		\
			ft_print_str.c			\
			ft_print_unsigned.c		\
			ft_print_void.c			\
			ft_print_wchar.c		\
			ft_print_wstr.c			\
			ft_printf.c				\
			ft_printnchar.c			\
			ft_putbase.c			\
			ft_retfield.c			\
			ft_char_to_int.c		\
			ft_char_to_short.c		\
			ft_lstadd.c				\
			ft_lstnew.c				\
			ft_lstdel.c				\
			ft_lstiter.c			\
			ft_lstpush.c

OBJ_NAME = $(SRC_NAME:.c=.o)
	OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
	SRC = $(addprefix $(SRC_PATH), $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo -en "\033[32mLibft.....\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "\033[32m      √\033[0m"

$(OBJ_PATH)%.o:%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I includes -c $<  -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHOONY: all clean fclean re
