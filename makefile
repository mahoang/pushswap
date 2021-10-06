# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 13:13:50 by zephyrus          #+#    #+#              #
#    Updated: 2021/10/06 00:32:58 by zephyrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = pushswap.h
SRC = main.c parsing.c instruct.c utils.c utils2.c algo.c
OPTION = -L ./mlx
OBJ = $(SRC:.c=.o)

CC = clang
FLAGS = -Wall -Wextra -o3 -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(OPTION) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean :	clean
	rm -rf $(NAME)

re : fclean all


norm :
	@ norminette $(SRC) $(HEADER)

.PHONY : clean fclean re all
