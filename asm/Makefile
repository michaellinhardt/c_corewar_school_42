# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:31:57 by abary             #+#    #+#              #
#    Updated: 2016/10/18 18:20:06 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

INC_DIR = includes

LIB_DIR = libft

INC_LIB_DIR = $(LIB_DIR)/$(INC_DIR)

NAME_LIB = asm.a\

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I $(INC_LIB_DIR)
#CFLAGS = -I$(INC_DIR) -I $(INC_LIB_DIR)

SRC = main.c  ft_lexer.c ft_lexer_name.c ft_open_file.c ft_get_size_file.c

SRCS = $(addprefix sources/,$(SRC))\

OBJ = $(SRCS:.c=.o)

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	(cd $(LIB_DIR) && $(MAKE))
	ar -r $(NAME_LIB) $(OBJ)
	#	gcc -o $(NAME) $(NAME_LIB) libft/libft.a  -ltermcap -lncurses -ltcl8.5
	gcc -o $(NAME) $(NAME_LIB) libft/libft.a 

clean :
	(cd $(LIB_DIR) && make clean && cd ..)
	rm -rf $(OBJ)

fclean : clean
	(cd $(LIB_DIR) && make fclean && cd ..)
	rm -rf $(NAME)
	rm -rf $(NAME_LIB)

re : fclean all

.PHONY: all clean fclean re
