/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm(t_dvm *v, int cperloop)
{
	while (--cperloop > -1)
		gameloop(v);
}
