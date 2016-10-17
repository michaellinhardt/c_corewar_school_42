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
	ft_printf("Live current period player : %d\n", v->live_player);
	ft_printf("max cheks : %d\n", v->max_checks);
	exit (0);
	exit1(0, data(), "dump order");
}

void	vm(t_dvm *v, int cperloop)
{
	// gameloop() exécute  un cycle, on l'appel cperloop fois,
	// selon la config du header ou des input clavier
	while (--cperloop > -1)
	{
		if (v->graphic && v->pause && data()->mlx.input.up == 0
		&& !(v->pause_inc))
			break ;
		v->pause_inc = 0;
		v->cycle++;
		if (!gameloop(v) || !v->proc)
		{
			// Ici la partie est terminé
			ft_printf("Contestant %d, \"%s\", has won !\n", ABS(v->last_live),
						v->p[(ABS(v->last_live)) -1].header.prog_name);
			if (v->dump != -1)
				vm_dump(v);
			exit1(0, data(), "game over");
		}
		if (v->dump == v->cycle)
		{
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
