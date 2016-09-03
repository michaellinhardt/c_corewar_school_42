/*
** GESTION DE LA GAMELOOP
*/
#include "ft_corewar.h"

/*
** Vérifie quel processus dois moourir, et appel la fonction proc_kill si besoin
** p est la liste des proc vivant dans data()->vm->proc
** reset le décompte de la prochaien vérif à la fin (v->ctodiecount = 0)
*/
int		checklive(t_dvm *v, t_proc *p, t_proc *next, int alive)
{
	l(-1, "checklive()", "there is cycle to die! burnnnnn ###");
	while (p && ((next = p->n) || 1))
	{
		// tue le process ou passe sont live à 0
		if (p->live < 1 && l2(-1, "checklive()", "kill process id", p->id))
			proc_kill(v, p, v->procdie);
		else if (++alive && !(p->live = 0))
			l2(-1, "checklive()", "alive process id", p->id);
		p = next;

	}
	l2(-1, "checklive()", "alive process count", alive);
	v->ctodiecount = 0;
	v->nbr_live = 0;

	// Debug
	next = v->proc;
	if (v->ctodie > 0)
		while (next && (next->live = 1))
			next = next->n;
	return (alive);
}

int		gameloop(t_dvm *v)
{
	// Début du cycle
	++v->cycle;
	if (!(v->cycle % 10))
		v->nbr_live += 4;
	l2(-1, "NEW CYCLE", "NEW CYCLE BEGING", v->cycle);
	if (++v->ctodiecount >= v->ctodie
	&& !checklive(v, v->proc, (t_proc *)NULL, 0))
		return (0);
	else if (((++v->max_checks >= MAX_CHECKS
	&& l2(11, "MAX_CHECKS LIMIT", "decrement c2die", (v->ctodie - CYCLE_DELTA)))
	|| (v->nbr_live >= NBR_LIVE
	&& l2(11, "NBR_LIVE LIMITS", "decrement c2die", (v->ctodie - CYCLE_DELTA))))
	&& !(v->max_checks = 0)
	&& !(v->nbr_live = 0))
		v->ctodie = ((v->ctodie - CYCLE_DELTA) > 0)
		? v->ctodie - CYCLE_DELTA : 0;
	return (1);
}
