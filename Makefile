# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 13:30:53 by abary             #+#    #+#              #
#    Updated: 2016/11/11 13:30:56 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re Asm Corewar sdl_install

all: Corewar Asm

Asm:
	make -CAsm

Corewar:
	make -CCorewar

clean:
	make clean -CCorewar
	make clean -CAsm

fclean:
	make fclean -CCorewar
	make fclean -CAsm

re:
	make re -CCorewar
	make re -CAsm

sdl_install :
	curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
	unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/
