/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm(t_dvm *v, int cperloop)
{
	while (--cperloop > -1)
	{
		if (!gameloop(v))
		{
			// Ici la partie est terminé
			exit1(0, data(), "game over");
		}
	}
}
