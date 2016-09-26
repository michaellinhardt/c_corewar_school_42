# VAR COMP
FLAGS	= -Wall -Wextra -Werror
CC		= gcc $(FLAGS)
INCS 	= -I./incs -I./libft/includes
LIBS	= ./libft
LIBFT 	= -L$(LIBS) -lft
LIBMLX	= -L./minilibx -lmlx -framework OpenGL -framework AppKit
LANGAGE	= c
NAME	= corewar

# VAR FOLDER/FILE
SRC_DIR = srcs
OBJ_DIR = objs

LIST 	= ft_corewar \
			ft_data \
			ft_mlx_init \
			ft_mlx_hook \
			ft_mlx_loop \
			ft_mlx_img \
			ft_mlx_scene \
			ft_mlx_scene_img \
			ft_mlx_scene_intro \
			ft_mlx_display \
			ft_mlx_display_arene \
			ft_terminal_ascii \
			ft_terminal_log \
			ft_vm_init \
			ft_vm \
			ft_recup_headers \
			ft_vm_processus \
			ft_vm_gameloop \
			ft_little_to_big \
			ft_recup_code \
			ft_fill_arene \
			ft_recup_files \
			ft_free \
			ft_exit \

SRC := $(addprefix $(SRC_DIR)/, $(addsuffix .$(LANGAGE), $(LIST)))
OBJ := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIST)))

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

all: $(NAME)

$(NAME): $(OBJ)
#@make -C $(LIBS)
	$(CC) $(OBJ) -o $@ $(FLAGS) $(INCS) $(LIBFT) $(LIBMLX)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(LANGAGE)
	@mkdir -p $(dir $@)
	$(CC) $(INCS) -o $@ -c $<

test: $(NAME)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] start"
	@./$(NAME)

clean:
#@make clean -C $(LIBS)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

clean2:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

fclean: clean2
	@/bin/rm -rf *.dSYM
#@make fclean -C $(LIBS)
	@/bin/rm -f $(NAME)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] bin deleted"

#leaks: $(NAME) -leaks
leaks: re
	./corewar

-leaks:
	@-valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

re: fclean libft $(NAME)

.PHONY: all clean clean2 fclean re libft test leaks
