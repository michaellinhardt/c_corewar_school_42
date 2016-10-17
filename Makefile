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
			ft_check_value_number \
			ft_mlx_display_processus \
			ft_get_indirect \
			ft_mlx_display_arene \
			ft_terminal_ascii \
			ft_terminal_log \
			ft_convert_pc \
			ft_vm_init \
			ft_vm \
			ft_recup_headers \
			ft_display_vm_papy \
			ft_vm_processus \
			ft_vm_processus_read \
			ft_vm_gameloop \
			ft_little_to_big \
			ft_recup_code \
			ft_fill_arene \
			ft_recup_files \
			ft_init_instructions \
			ft_init_instructions_end \
			ft_init_instructions_suite \
			ft_instructions_live \
			ft_instructions_ld \
			ft_instructions_st \
			ft_instructions_add \
			ft_instructions_sub \
			ft_instructions_and \
			ft_instructions_or \
			ft_instructions_xor \
			ft_instructions_zjmp \
			ft_instructions_ldi \
			ft_instructions_sti \
			ft_instructions_fork \
			ft_instructions_lld \
			ft_instructions_lldi \
			ft_instructions_lfork \
			ft_instructions_aff \
			ft_get_instructions \
			ft_recup_options \
			ft_put_registre \
			ft_get_args \
			ft_get_value_registre \
			ft_check_args \
			ft_fill_args \
			ft_getchar \
			ft_decode_args \
			ft_display_vm \
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
