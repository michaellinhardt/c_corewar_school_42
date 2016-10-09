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
	l2(-1, "checklive()", "cycle to die is coming!", v->cycle);
	while (p && ((next = p->n) || 1))
	{
		//l2(-3, "nbr live", "proc live", p->);
		// tue le process ou passe sont live à 0
		if (p->live < 1 && ++pdead
		&& l2(-3, "checklive()", "kill process", p->id))
			proc_kill(data(), p, data()->vm.procdie);
		else if ((palive += p->live) && !(p->live = 0))
			l2(-3, "checklive()", "live process", p->id);
		p = next;
	}
	l2(-1, "checklive()", "alive process count", v->nbr_proc);
	l2(-1, "checklive()", "dead process count", pdead);
	v->ctodiecount = 0;

	// décrémente le prochain cycle to die si nécessaire
	/*
	if (((++v->max_checks >= MAX_CHECKS
	&& l2(11, "MAX_CHECKS LIMIT", "decrement c2die (MAX CHECKS)", (v->ctodie - CYCLE_DELTA)))
	|| (v->nbr_live >= NBR_LIVE
	&& l2(11, "NBR_LIVE LIMITS", "decrement c2die (NBR LIVES)", (v->ctodie - CYCLE_DELTA))))
	&& !(v->max_checks = 0)
	&& !(v->nbr_live = 0))
		v->ctodie = ((v->ctodie - CYCLE_DELTA) > 0)
		? v->ctodie - CYCLE_DELTA : 0;

	v->nbr_live = 0;

	ft_printf("waaaaaaaaaaaagghhhhhhhhhhhhhhhhhhhhhh\n");
	*/
	if (v->nbr_live >= NBR_LIVE)
	{
		v->max_checks = 0;
		v->ctodie = v->ctodie - CYCLE_DELTA < 0 ? 0 : v->ctodie - CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", v->ctodie);
	}
	else if (((++v->max_checks >= MAX_CHECKS)))
	{
		v->max_checks = 0;
		v->ctodie = v->ctodie - CYCLE_DELTA < 0 ? 0 : v->ctodie - CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", v->ctodie);
	}
		v->nbr_live = 0;
	/*
	// Debug, met tout les process vivant
	next = data()->vm.proc;
	if (v->ctodie > 0)
	{
		while (next && (next->live = 1))
			next = next->n;
	}
	*/
	return (palive);
}

int		gameloop(t_dvm *v)
{
	int ret;
	ret= 0;
	// Début du cycle
//	++v->cycle;
	ft_printf("It is now cycle %d\n", v->cycle);
	processus_read(v, data()->vm.proc);
	v->ctodiecount++;
	if (v->ctodiecount >= v->ctodie
	&& !(ret = checklive(v, data()->vm.proc, (t_proc *)NULL, 0, 0)))
		return (0);
	return (1);
}
