# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:31:57 by abary             #+#    #+#              #
#    Updated: 2016/10/26 21:28:32 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

INC_DIR = includes

LIB_DIR = libft

INC_LIB_DIR = $(LIB_DIR)/$(INC_DIR)

NAME_LIB = asm.a\

#CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I $(INC_LIB_DIR)
CFLAGS = -I$(INC_DIR) -I $(INC_LIB_DIR)

SRC = main.c  ft_open_file.c ft_get_size_file.c\
	  ft_init_lexer.c ft_display_tokenisation.c\
	  ft_get_line.c ft_free.c ft_init_instructions.c\
	  ft_init_instructions_end.c ft_init_instructions_suite.c

SRC_LEXER = ft_lexer.c ft_lexer_register.c ft_lexer_endline.c ft_lexer_end.c\
	ft_lexer_separator.c ft_lexer_label.c ft_lexer_direct.c\
	ft_lexer_comment.c ft_lexer_string.c ft_lexer_whitespace.c\
	ft_lexer_command_name.c ft_lexer_command_comment.c\
	ft_lexer_instruction.c ft_lexer_indirect.c ft_lexer_direct_label.c\
	ft_lexer_value.c ft_lexer_indirect_label.c  ft_lexer_error.c

SRC_PARSER = ft_parser.c ft_parse_tree.c ft_parser_shift.c\
			ft_parser_reduce.c ft_parser_pile_tree.c\
			ft_parser_accept.c ft_check_name_instructions.c ft_init_parser.c\
			ft_parser_rule_endline.c ft_parser_rule_instruction.c \
			ft_parser_rule_name.c ft_parser_rule_ccomment.c\
			ft_parser_check_shift.c ft_parser_rule_separator_char.c\
			ft_parser_rule_argument.c ft_parser_check_accept.c\
			ft_parser_verif_instruction.c ft_free.c

SRCS = $(addprefix sources/,$(SRC))\
	   $(addprefix sources/lexer/,$(SRC_LEXER))\
	   $(addprefix sources/parser/,$(SRC_PARSER))

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
