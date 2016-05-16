# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:02:34 by cjacques          #+#    #+#              #
#    Updated: 2016/05/16 17:18:18 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SHELL = /bin/bash
LIB = libft/
ASM = ASM/
VM = vm/

all:
	@echo -e "\033[32mCompile...\033[0m"
	@make -C $(LIB) all
	@make -C $(ASM) all
	@make -C $(VM) all
	@echo -e "\033[32mDone\033[0m"

clean:
	@echo -e "\033[32mClean\033[0m"
	@make -C $(LIB) clean
	@make -C $(ASM) clean
	@make -C $(VM) clean

fclean: clean
	@make -C $(LIB) fclean
	@make -C $(ASM) fclean
	@make -C $(VM) fclean

re: fclean all

.PHONY: all clean fclean re
