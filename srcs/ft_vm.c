/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm_dump(t_dvm *v)
{
	l2(12, "BYE BYE", "dump cycle", v->cycle);
	ft_display_vm(v);
	ft_printf(" nbr cycles : : %d\n", v->cycle);
	ft_printf("Nombre de proc : %d\n", v->nbr_proc);
	ft_printf("Cycle to die : %d\n", v->ctodie);
	ft_printf("Last live cycle : %d\n", v->last_live_cycle);
	ft_printf("Live current period : %d\n", v->nbr_live);
	exit (0);
	exit1(0, data(), "dump order");
}

void	vm(t_dvm *v, int cperloop)
{
	// gameloop() exécute  un cycle, on l'appel cperloop fois,
	// selon la config du header ou des input clavier
//	static int loop = 0;
	while (--cperloop > -1)
	{
		v->cycle++;
		if (!gameloop(v) || !v->proc)
		{
			// Ici la partie est terminé
			ft_printf("Last Live MF : %d\n", v->last_live);
			if (v->dump != -1)
				vm_dump(v);
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
	if (v->dump <= v->cycle && v->dump != -1)
			vm_dump(v);
}
