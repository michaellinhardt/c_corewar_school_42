#ifndef FT_STRUCT_VM_H
# define FT_STRUCT_VM_H
/*
 *	Header des données lié a la vm et gameloop
 */

 /* VM_PLAYER
  * donné lié a la vm, au champion et a l'arene
  */
typedef struct			s_player
{
  char              name[CHAMP_MAX_SIZE];
}					        	t_player;

/*
** DATA_VM
** donné lié a la vm, au champion et a l'arene
** Pour y acceder: data()->vm.players[0]->name
*/
typedef struct			s_dvm
{
  t_player          players[4];
}					        	t_dvm;

#endif

// t_player player(int index)
// {
//   return data()->vm.players[index];
// }
// 
// player(2).
