#ifndef FT_STRUCT_VM_H
# define FT_STRUCT_VM_H
/*
 *	Header des données lié a la vm et gameloop
 */

 /* VM_PLAYER
  * donné lié a la vm, au champion et a l'arene
  */
typedef struct			s_proc
{
	// l'état live -> -1 pour mort, 0 pour vivant, 1 pour à déjà fais sont live
	int					id;
	int					player;
	int					live;
	int					i;
	struct s_proc		*n;
	struct s_proc		*p;

}						t_proc;

/* VM_PLAYER
 * donné lié a la vm, au champion et a l'arene
 */
typedef struct			s_player
{
	char				name[CHAMP_NAME_SIZE];
	char				code[CHAMP_MAX_SIZE];
	int					playing;
}						t_player;

/*
** DATA_VM
** donné lié a la vm, au champion et a l'arene
** Pour y acceder: data()->vm.players[0]->name
*/
typedef struct			s_dvm
{
	t_player			p[MAX_PLAYERS];
	char				arene[MEM_SIZE];
	int					cycle;
	int					cperloop;
	int					ctodie;
	int					ctodiecount;
	int					nbr_live;
	int					max_checks;
	t_proc				*proc;
	t_proc				*procdie;
}						t_dvm;

#endif

// t_player player(int index)
// {
//   return data()->vm.players[index];
// }
//
// player(2).
