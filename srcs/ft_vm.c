/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm_dump(t_dvm *v)
{
	l2(12, "BYE BYE", "dump cycle", v->cycle);
	exit1(0, data(), "dump order");
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
			ft_printf("Last Live MF : %d\n", v->last_live);
			exit1(0, data(), "game over");
		}
		if (v->dump == v->cycle)
		{
			// il serais bon dafficher un ecran special pour préciser
			// que la parti s'arrete suite a un dump
			// a paufiner plus tard ...
			if (v->graphic)
				display(&(data()->mlx), v);
			vm_dump(v);
		}
	}
	// lance l'affichage si necessaire
	if (v->graphic)
		display(&(data()->mlx), v);
}
