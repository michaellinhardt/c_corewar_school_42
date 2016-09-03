/*
** GESTION DE LA GAMELOOP
*/
#include "ft_corewar.h"

/*
** Vérifie quel processus dois moourir, et appel la fonction proc_kill si besoin
** p est la liste des proc vivant dans data()->vm->proc
** reset le décompte de la prochaien vérif à la fin (v->ctodiecount = 0)
*/
void	checklive(t_dvm *v, t_proc *p)
{
	while (p)
		if (p->live < 1 && proc_kill(v, p, v->procdie) && (p = p->n))
			continue ;
	v->ctodiecount = 0;
}

void	gameloop(t_dvm *v)
{
	// Début du cycle
	++v->cycle;
	// Controle si on dois décrémenter le nombre de cycle to die
	if ((v->nbr_live >= NBR_LIVE || v->max_checks++ >= MAX_CHECKS)
	&& !(v->nbr_live = 0)
	&& !(v->max_checks = 0))
		v->ctodie = ((v->ctodie - CYCLE_DELTA) > 0)
		? v->ctodie - CYCLE_DELTA : 0;
	// Lance la fonction qui tue les process qui n'on pas fais de live
	if (++v->ctodiecount >= v->ctodie)
		checklive(v, v->proc);
	checklive(v, v->proc);
	ft_printf("gameloop bitch");
	exit1(0, data(), "test");
}
