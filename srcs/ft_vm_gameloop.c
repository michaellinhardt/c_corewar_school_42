/*
** GESTION DE LA GAMELOOP
*/
#include "ft_corewar.h"

void	checklive(t_dvm *v)
{
	// fonction qui tue les process n'ayant pas fais de live
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
		checklive(v);
	ft_printf("gameloop bitch");
	exit (0);
}
