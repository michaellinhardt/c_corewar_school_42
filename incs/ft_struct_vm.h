#ifndef FT_STRUCT_VM_H
# define FT_STRUCT_VM_H
/*
 *	Header des données lié a la vm et gameloop
 */
# define SIZE_CHAR_ARENE (MEM_SIZE * 2)

 /* VM_PROC
  * donné lié a la vm, au champion et a l'arene
  */


typedef struct	s_dvm t_dvm;
typedef struct	s_proc t_proc;

// index de t_instructions => opcode (donc index 0 vide)
typedef	struct		s_instructions
{
	char			name[6]; // le nom de l'instruction
	short			nbr_args; // son nombre d'args
	t_arg_type		types[MAX_ARGS_NUMBER];
	int				cycles;
	char			comment[37];
	int				flag_ocp; // si ocp pour decode
	int				flag_size_ind;
	// pointeur vers la fonctions d'instructions
	void			(*f_instructions)(t_dvm *vm, struct s_instructions ins,
			t_proc *proc);
}					t_instructions;

typedef	struct		s_argument
{
	int				value;
	char			type;
}					t_argument;

typedef struct		s_proc
{
	// l'état live -> -1 pour mort, 0 pour vivant, 1 pour à déjà fais sont live
	int				id;
	int				player;
//	int				player_live;
	int				create_cycle;
	int				live;
	int				wait;
	int				pc;
	int				pc_turfu;
	char			reg[REG_NUMBER][REG_SIZE];
	int				*ireg;
	char			carry;
	char			last;
	t_argument		args[MAX_ARGS_NUMBER];
	t_instructions	*inst; // instruction courante
	struct s_proc	*n;
	struct s_proc	*p;
}					t_proc;

/* VM_PLAYER
 * donné lié a la vm, au champion et a l'arene
 */
typedef struct		s_player
{
	struct header_s	header;
	/*
	char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
	*/
	char			code[CHAMP_MAX_SIZE]; // heu
	int				playing;
	int				total_live;
	int				last_cycle_live;
}					t_player;

/*
** DATA_VM
** donné lié a la vm, au champion et a l'arene
** Pour y acceder: data()->vm.players[0]->name
*/
typedef struct		s_dvm
{
	t_player		p[MAX_PLAYERS];
	t_instructions	instructions[17];
	char			arene[SIZE_CHAR_ARENE];
	int				color[MEM_SIZE];
	int				code_color[5];
	char			code[MEM_SIZE]; // useless
	char			console;
	char			graphic;
	int				dump;
	int				cycle;
	int				cperloop;
	int				ctodie;
	int				ctodiecount;
	int				nbr_live;
	int				max_checks;
	int				last_live;
	int				last_live_cycle;
	int				nbr_players;
	int				nbr_proc;
	t_proc			*proc;
	t_proc			*procdie;

	// Tableau de pointeur sur fonctions des instructions
}					t_dvm;

#endif
