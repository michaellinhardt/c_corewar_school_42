# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/04 04:52:57 by pba               #+#    #+#              #
#    Updated: 2016/09/04 20:28:30 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:

.SUFFIXES:

CFLAGS			= -Wall -Werror -Wextra
CHAMPION		= champion.cor
HPATH_ASM		= includes/
HPATH_LIBFT		= ../libft/includes
SPATH_ASM		= src/
OPATH_ASM		= obj/

SRC				= compile.c \
				  lexer.c \
				  list_manager.c

OBJ				= $(SRC:%.c=$(OPATH_ASM)%.o)

all: mkdir_obj champion.cor

$(CHAMPION): $(OBJ)
	@echo "\033[32;01mobject files created.\033[0m"
	@echo "\033[36;01mcompiling libft...\033[0m"
	make -C ../libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	gcc -o $(CHAMPION) $(OBJ) -L../libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"
	@echo "\033[32;01mchampion.cor created.\033[0m\n"

$(OPATH_ASM)%.o: $(SPATH_ASM)%.c
	gcc $(CFlAGS) -c $< -I $(HPATH_LIBFT) -I $(HPATH_ASM) -o $@

mkdir_obj:
	mkdir -p $(OPATH_ASM)
	@echo "\033[32;01mobj/ folder created.\033[0m"

clean:
	rm -rf $(OBJ)
	@echo "object files deleted."

fclean: clean
	rm -rf $(CHAMPION)
	@echo "$(CHAMPION) deleted"

re: fclean all
