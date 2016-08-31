# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2016/08/28 17:45:45 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: vm, mkdir_obj, mkdir_obj_vm, clean, fclean

.SUFFIXES:

CFLAGS			= -Wall -Werror -Wextra
SERVER			= server
CLIENT			= client
HPATH_VM		= includes/
HPATH_LIBFT 	= ../libft/includes/
SPATH_SERVER	= src_server/
SPATH_CLIENT	= src_client/
OPATH_SERVER	= obj_server/
OPATH_CLIENT	= obj_client/

SRC_SERVER		= server.c \
				  create_server.c \
				  init_env.c \
				  request.c \
				  parser.c \
				  check_champion.c

SRC_CLIENT		= client.c \
				  create_client.c \
				  read_until_notif.c


OBJ_SERVER		= $(SRC_SERVER:%.c=$(OPATH_SERVER)%.o)
OBJ_CLIENT		= $(SRC_CLIENT:%.c=$(OPATH_CLIENT)%.o)

all: mkdir_obj server client

$(SERVER): $(OBJ_SERVER)
	@echo "\033[32;01mVM object files created.\033[0m"
	@echo "\033[36;01mcompiling libft...\033[0m"
	@make re -C ../libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(SERVER) $(OBJ_SERVER) -L../libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"
	@echo "\033[32;01mserver created.\033[0m\n"
	@echo "\033[31;01mSERVER READY FOR USE !\033[0m\n"

$(CLIENT): $(OBJ_CLIENT)
	@echo "\033[32;01mVM object files created.\033[0m"
	@echo "\033[36;01mcompiling libft...\033[0m"
	@make re -C ../libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(CLIENT) $(OBJ_CLIENT) -L../libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"
	@echo "\033[32;01mclient created.\033[0m\n"
	@echo "\033[31;01mCLIENT READY FOR USE !\033[0m\n"

$(OPATH_SERVER)%.o: $(SPATH_SERVER)%.c
	@gcc $(CFLAGS) -c $< -I $(HPATH_LIBFT) -I $(HPATH_VM) -o $@

$(OPATH_CLIENT)%.o: $(SPATH_CLIENT)%.c
	@gcc $(CFLAGS) -c $< -I $(HPATH_LIBFT) -I $(HPATH_VM) -o $@

mkdir_obj_server:
	@mkdir -p $(OPATH_SERVER)
	@echo "\033[32;01mobj_server/ folder created.\033[0m"

mkdir_obj_client:
	@mkdir -p $(OPATH_CLIENT)
	@echo "\033[32;01mobj_client/ folder created.\033[0m"

mkdir_obj: mkdir_obj_server mkdir_obj_client

clean_server:
	@rm -rf $(OBJ_SERVER)
	@echo "server object files deleted."

clean_client:
	@rm -rf $(OBJ_CLIENT)
	@echo "client object files deleted."

clean: clean_server clean_client

fclean_server: clean_server
	@rm -rf $(SERVER)
	@echo "$(SERVER) deleted."

fclean_client: clean_client
	@rm -rf $(CLIENT)
	@echo "$(CLIENT) deleted."

fclean: fclean_server fclean_client

re_server: fclean_server mkdir_obj_server $(SERVER)

re_server: fclean_client mkdir_obj_client $(CLIENT)

re: fclean all
