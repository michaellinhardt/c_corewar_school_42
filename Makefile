# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:31:57 by abary             #+#    #+#              #
#    Updated: 2016/08/10 12:58:12 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

INC_DIR = includes

LIB_DIR = libft

INC_LIB_DIR = $(LIB_DIR)/$(INC_DIR)

NAME_LIB = corewar.a\

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I $(INC_LIB_DIR)

SRC = main.c

SRCS = $(addprefix sources/,$(SRC))

OBJ = $(SRCS:.c=.o)
CC = gcc
all : $(NAME)

$(NAME) : $(OBJ)
	(cd $(LIB_DIR) && $(MAKE))
	ar -r $(NAME_LIB) $(OBJ)
	gcc -o $(NAME) $(NAME_LIB) libft/libft.a  -ltermcap -lncurses -ltcl8.5

clean :
	(cd $(LIB_DIR) && make clean && cd ..)
	rm -rf $(OBJ)

fclean : clean
	(cd $(LIB_DIR) && make fclean && cd ..)
	rm -rf $(NAME)
	rm -rf $(NAME_LIB)

re : fclean all

.PHONY: all clean fclean re
