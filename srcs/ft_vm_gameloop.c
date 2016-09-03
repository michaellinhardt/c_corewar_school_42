/*
** GESTION DE LA GAMELOOP
*/
#include "ft_corewar.h"

/*
** Vérifie quel processus dois moourir, et appel la fonction proc_kill si besoin
** p est la liste des proc vivant dans data()->vm->proc
** reset le décompte de la prochaien vérif à la fin (v->ctodiecount = 0)
*/
void	checklive(t_dvm *v, t_proc *p, t_proc *next)
{
	l(-1, "checklive()", "there is cycle to die! burnnnnn ###");

	while (p && ((next = p->n) || 1))
	{
		if (p->live < 1 && l2(-1, "checklive()", "kill process id", p->id))
			proc_kill(v, p, v->procdie);
		else
			l2(-1, "checklive()", "alive process id", p->id);
		p = next;
	}
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
		checklive(v, v->proc, (t_proc *)NULL);



	// DEBUG MET TOUT LE MONDE VIVANT
	v->proc->live = 1; // 3
	(v->proc->n)->live = 1; // 2
	((v->proc->n)->n)->live = 0; // 1
	(((v->proc->n)->n)->n)->live = 1; // 0
	// PHASE DE TEST DE LA GESTION DES PROCESSUS
	checklive(v, v->proc, (t_proc *)NULL);
	checklive(v, v->proc, (t_proc *)NULL);
	proc_new(v, (t_proc *)NULL, 1, 1);
	v->proc->live = 1;
	checklive(v, v->proc, (t_proc *)NULL);
	proc_new(v, (t_proc *)NULL, 1, 1);
	proc_new(v, (t_proc *)NULL, 1, 1);
	v->proc->live = 1;
	(v->proc)->n->live = 1;
	checklive(v, v->proc, (t_proc *)NULL);
	((((v->proc)->n)->n)->n)->live = 0;
	checklive(v, v->proc, (t_proc *)NULL);
	proc_new(v, (t_proc *)NULL, 1, 1);
	v->proc->live = 1;
	checklive(v, v->proc, (t_proc *)NULL);


	exit1(0, data(), "test");
}
