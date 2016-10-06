/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm_dump(t_dvm *v)
{
	int i;
	l2(12, "BYE BYE", "dump cycle", v->cycle);
	ft_display_vm(v);
	ft_printf("Nombre de proc : %d\n", v->nbr_proc);
	i = 0;
	while(v->proc)
	{
		++i;
		v->proc = v->proc->n;
	}
	ft_printf("TOTAL : %d\n", i);
	exit1(0, data(), "dump order");
}

void	vm(t_dvm *v, int cperloop)
{
	// gameloop() exécute  un cycle, on l'appel cperloop fois,
	// selon la config du header ou des input clavier
//	static int loop = 0;
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
		v->cycle++;
	}
	// lance l'affichage si necessaire
	if (v->graphic)
		display(&(data()->mlx), v);
	if (v->dump <= v->cycle && v->dump != -1)
			vm_dump(v);
}
