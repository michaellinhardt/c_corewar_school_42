/*
** GESTION DE LA GAMELOOP
*/
#include "ft_corewar.h"

/*
** Vérifie quel processus dois moourir, et appel la fonction proc_kill si besoin
** p est la liste des proc vivant dans data()->vm->proc
** reset le décompte de la prochaien vérif à la fin (v->ctodiecount = 0)
*/
int		checklive(t_dvm *v, t_proc *p, t_proc *next, int palive, int pdead)
{


	(void)next;

	while (p)
	{
		if (p->live < 1)
		{

			next = p->n;
			++pdead;
			proc_kill(data(), p, data()->vm.procdie);
			if (next)
			{
				p = next;
				continue;
			}
			else
				break;
		}
		if (p)
		{
			p->live = 0;
			p->live_player = 0;
		}
		p = p->n;
	}
	v->ctodiecount = 0;


	if (v->live_player >= NBR_LIVE)
	{
		v->max_checks = 1;
		v->ctodie = v->ctodie - CYCLE_DELTA < 0 ? 0 : v->ctodie - CYCLE_DELTA;
		if (v->options.cycles)
			ft_printf("Cycle to die is now %d\n", v->ctodie);
	}
	else if (((v->max_checks >= MAX_CHECKS)))
	{
		v->max_checks = 1;
		v->ctodie = v->ctodie - CYCLE_DELTA < 0 ? 0 : v->ctodie - CYCLE_DELTA;
		if (v->options.cycles)
			ft_printf("Cycle to die is now %d\n", v->ctodie);
	}
	else
		v->max_checks++;
	palive = v->nbr_live;
	v->nbr_live = 0;
	v->live_player = 0;
	return (palive);
}

int		gameloop(t_dvm *v)
{
	int ret;
	ret= 0;

	// Début du cycle
	//	++v->cycle;
	//	ft_printf("It is now cycle %d\n", v->cycle);
	processus_read(v, data()->vm.proc);
	v->ctodiecount++;
	if (v->ctodiecount >= v->ctodie
			&& !(ret = checklive(v, data()->vm.proc, (t_proc *)NULL, 0, 0)))
		return (0);
	return (1);
}
