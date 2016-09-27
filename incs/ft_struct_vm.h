#ifndef FT_STRUCT_VM_H
# define FT_STRUCT_VM_H
/*
 *	Header des données lié a la vm et gameloop
 */
# define SIZE_CHAR_ARENE (MEM_SIZE * 2)

 /* VM_PROC
  * donné lié a la vm, au champion et a l'arene
  */
typedef struct		s_proc
{
	// l'état live -> -1 pour mort, 0 pour vivant, 1 pour à déjà fais sont live
	int				id;
	int				player;
	int				live;
	int				i;
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
}					t_player;

/*
** DATA_VM
** donné lié a la vm, au champion et a l'arene
** Pour y acceder: data()->vm.players[0]->name
*/
typedef struct		s_dvm
{
	t_player		p[MAX_PLAYERS];
	char			arene[SIZE_CHAR_ARENE + 1];
	int				color[MEM_SIZE];
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
	int				nbr_players;
}					t_dvm;

#endif
