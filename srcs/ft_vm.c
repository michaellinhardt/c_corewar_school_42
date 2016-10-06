/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

void	vm_dump(t_dvm *v)
{
	l2(12, "BYE BYE", "dump cycle", v->cycle);
	ft_display_vm(v);
	exit1(0, data(), "dump order");
}

void	vm(t_dvm *v, int cperloop)
{
	while (--cperloop > -1)
	{
		if (!gameloop(v)
		&& l2(1, "LAST_LIVE", "(v->last_live) is the winner", v->last_live))
			exit1(0, data(), "game over");
		else if (v->dump == v->cycle
		&& l2(1, "DUMP_ORDER", "(cycle) call vm_dump()", v->cycle))
		{
			if ((v->graphic && display(&(data()->mlx), v)) || 1)
				vm_dump(v);
		}
		else if (data()->mlx.loop && v->graphic
		&& l1(100, "(loop == 1)", "overide cperloop, call display()")
		&& display(&(data()->mlx), v) && ++v->cycle)
			break ;
		else
			v->cycle++;
	}
	// lance l'affichage si necessaire
	if (!(data()->mlx.loop) && v->graphic)
		display(&(data()->mlx), v);
	if (v->dump <= v->cycle && v->dump != -1)
			vm_dump(v);
}
