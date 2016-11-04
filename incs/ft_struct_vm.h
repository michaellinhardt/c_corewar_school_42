#ifndef FT_STRUCT_VM_H
# define FT_STRUCT_VM_H
# include "ft_struct_inst.h"
# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define REG_NUMBER				16
# define REG_SIZE				4
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

typedef	struct		s_argument
{
	int				value;
	char			type;
}					t_argument;

typedef struct		s_proc
{
	int				id;
	int				player;
	int				create_cycle;
	int				mlx_status;
	int				live;
	int				last_live;
	int				live_player;
	int				wait;
	int				pc;
	int				pc_turfu;
	char			reg[REG_NUMBER][REG_SIZE];
	int				*ireg;
	char			carry;
	t_argument		args[MAX_ARGS_NUMBER];
	t_instructions	*inst;
	struct s_proc	*n;
	struct s_proc	*p;
}					t_proc;

typedef struct		s_player
{
	t_header		header;
	char			code[CHAMP_MAX_SIZE];
	int				playing;
	int				total_live;
	int				total_live_current;
	int				total_proc_alive;
	int				total_proc_dead;
	int				last_cycle_live;
}					t_player;

typedef struct		s_options
{
	char			lives:1;
	char			cycles:1;
	char			operations:1;
	char			deaths:1;
	char			movements:1;
}					t_options;

typedef struct		s_dvm
{
	t_player		p[MAX_PLAYERS];
	t_instructions	instructions[17];
	t_options		options;
	char			arene[8192];
	int				color[MEM_SIZE];
	int				code_color[9];
	int				color_proc;
	char			code[MEM_SIZE];
	char			console;
	char			consolee;
	char			graphic;
	int				dump;
	char			pause;
	char			pause_inc;
	int				cycle;
	int				cperloop;
	int				ctodie;
	int				ctodiecount;
	int				nbr_live;
	int				nbr_live_current;
	int				max_checks;
	int				total_live;
	int				last_live;
	int				last_live_cycle;
	int				live_player;
	int				nbr_players;
	int				nbr_proc;
	int				nbr_proc_dead;
	t_proc			*proc;
	Mix_Music		*son;
}					t_dvm;
#endif
