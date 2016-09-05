/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	display(t_dvm *v)
{
	v->cperprintcount = 0;
	l2(-2, "PUSH TO WINDOW", "preparing data, cycle", v->cycle);
}

void	vm(t_dvm *v, int cperloop)
{
	while (--cperloop > -1)
	{
		if (!gameloop(v))
		{
			// Ici la partie est terminé
			exit1(0, data(), "game over");
		}
		(++v->cperprintcount >= CYCLE_PER_PRINT) ? display(v) : (void)NULL;
	}
}
