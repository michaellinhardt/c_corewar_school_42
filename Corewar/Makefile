# VAR COMP
FLAGS	= -Wall -Wextra -Werror -O3 -march=native
CC		= gcc
LINCS	= ./libft/includes
MLX_INC	= ./minilibx
INCS	= -I ../incs -I $(MLX_INC) -I $(LINCS)
LIBS	= ./libft
LIBFT 	= -L$(LIBS) -lft -lm
MLX_PATH = ./minilibx/
LIBMLX	= -L./minilibx -lmlx -framework OpenGL -framework Appkit
LANGAGE	= c
NAME	= corewar
SDL2		= -framework SDL2
SDL2_MIXER	= -framework SDL2_mixer

SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER	= -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/

SDL			= -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER	= -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)


# VAR FOLDER/FILE
SRC_DIR = srcs
OBJ_DIR = objs

LIST	=	ft_corewar.c \
			ft_data.c \
			ft_mlx_init.c \
			ft_mlx_hook.c \
			ft_mlx_loop.c \
			ft_mlx_img.c \
			ft_mlx_scene.c \
			ft_mlx_scene_img.c \
			ft_mlx_scene_intro.c \
			ft_mlx_display.c \
			ft_check_value_number.c \
			ft_get_indirect.c \
			ft_mlx_display_cycle.c \
			ft_mlx_display_effect.c \
			ft_mlx_display_processus.c \
			ft_mlx_display_player_name.c \
			ft_mlx_display_processus_count.c \
			ft_mlx_display_bar_proc_live_current.c \
			ft_mlx_display_bar_proc_live.c \
			ft_mlx_display_bar_proc_dead.c \
			ft_mlx_display_bar_proc.c \
			ft_mlx_display_arene.c \
			ft_mlx_effect_init.c \
			ft_mlx_end.c \
			ft_terminal_ascii.c \
			ft_terminal_log.c \
			ft_convert_pc.c \
			ft_vm_init.c \
			ft_vm.c \
			ft_recup_headers.c \
			ft_display_vm_papy.c \
			ft_vm_processus.c \
			ft_vm_processus_read.c \
			ft_vm_gameloop.c \
			ft_little_to_big.c \
			ft_recup_code.c \
			ft_fill_arene.c \
			ft_recup_files.c \
			ft_init_instructions.c \
			ft_init_instructions_end.c \
			ft_mlx_put_mid_img_3.c \
			ft_init_instructions_suite.c \
			ft_instructions_live.c \
			ft_instructions_ld.c \
			ft_instructions_st.c \
			ft_instructions_add.c \
			ft_instructions_sub.c \
			ft_instructions_and.c \
			ft_instructions_or.c \
			ft_instructions_xor.c \
			ft_instructions_zjmp.c \
			ft_instructions_ldi.c \
			ft_instructions_sti.c \
			ft_instructions_fork.c \
			ft_instructions_lld.c \
			ft_instructions_lldi.c \
			ft_instructions_lfork.c \
			ft_instructions_aff.c \
			ft_get_instructions.c \
			ft_recup_options.c \
			ft_display_help.c \
			ft_put_registre.c \
			ft_get_args.c \
			ft_get_value_registre.c \
			ft_check_args.c \
			ft_fill_args.c \
			ft_getchar.c \
			ft_decode_args.c \
			ft_display_vm.c \
			ft_free.c \
			ft_exit.c \

OBJO = $(LIST:.c=.o)
SRC = $(addprefix $(SRC_DIR)/, $(LIST))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJO))

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

.PHONY: all clean clean2 fclean re test leaks -leaks ready sdl_install

all: $(NAME)

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(LANGAGE)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) $(INCS) $(SDL_HEADER) $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBS)
	@make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(SDL) $(SDL_HEADER)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] created"

test: $(NAME)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] start"
	@./$(NAME)

clean:
	@make clean -C $(LIBS)
	@make clean -C $(MLX_PATH)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

clean2:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

fclean: clean
	@/bin/rm -rf *.dSYM
	@make fclean -C $(LIBS)
	@/bin/rm -f $(NAME)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] bin deleted"

#leaks: $(NAME) -leaks
leaks: $(NAME)
	./corewar ./zaz/bee_gees.cor ./zaz/bee_gees.cor ./zaz/bee_gees.cor ./zaz/bee_gees.cor

-leaks:
	@-valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

ready: re clean
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "$(NAME) is ready ! 🍺  and cleaned poop 💩"

re: fclean all
