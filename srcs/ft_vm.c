/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm_dump(t_dvm *v)
{
	l2(12, "BYE BYE", "dump cycle", v->cycle);
	exit1(0, data(), "dump order");
}

void	vm_display(t_dvm *v)
{
	v->cperprintcount = 0;
	l2(-2, "PUSH TO WINDOW", "preparing data, cycle", v->cycle);
}

void	vm(t_dvm *v, int cperloop)
{
	// gameloop() exécute  un cycle, on l'appel cperloop fois,
	// selon la config du header ou des input clavier
	while (--cperloop > -1)
	{
		if (!gameloop(v))
		{
			// Ici la partie est terminé
			exit1(0, data(), "game over");
		}
		// lance l'affichage si necessaire
		if (v->graphic && ++v->cperprintcount >= CYCLE_PER_PRINT)
			vm_display(v);
		if (v->dump == v->cycle)
			vm_dump(v);
	}
}
