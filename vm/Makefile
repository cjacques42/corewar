# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/22 21:11:26 by stoussay          #+#    #+#              #
#    Updated: 2016/05/19 19:37:54 by stoussay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
SRC = corewar.c live.c init_player.c debug.c game.c processes_manager.c \
op_parser.c zjmp.c fork.c lfork.c add.c aff.c and.c ld.c ldi.c lld.c lldi.c \
or.c st.c sti.c sub.c xor.c utils.c ncurse_manager.c args.c utils2.c args2.c\
ncurse_printing.c init_player_utils.c utils3.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -Iincludes

OBJ_PATH = $(addprefix obj/, $(OBJ))
SRC_PATH = srcs/
OP_PATH = srcs/op/
LIBFT_PATH = ../libft

all: $(NAME)

save: fclean
	git add --all
	git commit -m "Autosaving of corewar"
	git push

$(NAME): $(OBJ_PATH)
		@echo "\033[35mLibft.a created."
		@gcc $(FLAGS) $(OBJ_PATH) -L./$(LIBFT_PATH) -lft -lncurses -o $(NAME)
		@echo "corewar created."

obj/%.o : $(SRC_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAGS) -c $^ -o $@

obj/%.o : $(OP_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAGS) -c $^ -o $@

.PHONY: clean fclean

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)

re : fclean all
