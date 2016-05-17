# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:02:34 by cjacques          #+#    #+#              #
#    Updated: 2016/05/17 12:25:21 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ_PATH = obj/
SRC_PATH = srcs/
SHELL = /bin/bash
LIB = ../libft/

SRC_NAME =	main.c			\
			error.c			\
			parse_header.c	\
			parse_body.c	\
			utils.c			\
			check.c			\
			args.c			\
			check_reg.c		\
			check_dir.c		\
			check_ind.c		\
			print.c			\
			binary.c		\
			bin_header.c	\
			free.c			\
			token.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I includes -L $(LIB) -lft

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I includes -c $^ -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)
save:
	@make -C ../ fclean
	git pull
	git add --all
	git commit -m "ASM update"
	git push

re: fclean all

.PHONY: all clean fclean re
