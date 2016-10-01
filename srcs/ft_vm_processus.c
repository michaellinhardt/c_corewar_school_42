/*
** GESTION DES PROCESSUS
*/
#include "ft_corewar.h"

void	proc_new(t_data *d, t_proc *new, int player, int i)
{
	// FONCTION QUI RECUPERE UN PROCESSUS MORT OU EN CREER UN NOUVEAU
	static int	id = -1;
	int			setid;

	// Récupére un proc mort si il existe, sinon le créer
	// nb. c'est aussi ici qu'on détermine l'id associé au process avec setid
	setid = 0;
	if (d->procdie && (new = d->procdie)
	&& (((setid = d->procdie->id) || 1))
	&& ((d->procdie = d->procdie->n) || 1)
	&& ((d->procdie && ((d->procdie->p = (t_proc *)NULL) || 1)) || 1))
		l2(12, "PROC RESURECT", "id", setid);
	else if ((((setid = ++id) || 1)) && l2(12, "PROC MALLOC", "id", setid)
	&& !(new) && !(new = (t_proc *)ft_memalloc(sizeof(t_proc))))
		exit1(1, data(), "Can't malloc struct s_proc");


	ft_bzero(new, sizeof(new));
	// positionne le processus dans la liste d->proc à l'endroit ou il devrait
	// se trouver (avec les liens next et previous correspondant)
	if (d->proc && (new->n = d->proc))
		(d->proc)->p = new;
	else
		new->n = (t_proc *)NULL;
	new->p = (t_proc *)NULL;
	d->proc = new;

	// régle les valeur du proc
	new->ireg = (int *)new->reg;
	new->ireg[0] = player;
	new->player = player;
	new->pc = i;
	new->id = setid;
	d->vm.nbr_proc++;
	l2(-1, "PROC SETTINGS", "player attribution", player);
	l2(-1, "PROC SETTINGS", "id processus", setid);
	l2(-1, "PROC SETTINGS", "arene start value", i);
}

/*
** FONCTION QUI TUE LES PROCESS ET LES PLACE DAnS LA LISTE MORTE
*/
int		proc_kill(t_data *d, t_proc *target, t_proc *procdie)
{
	if (target->p)
		(target->p)->n = target->n;
	if (target->n)
		(target->n)->p = target->p;
	if (d->proc == target)
		d->proc = target->n;

	// déplace le maillon
	if (procdie && (target->n = procdie))
		procdie->p = target;
	target->p = (t_proc *)NULL;
	d->vm.nbr_proc--;
	return (1);
}
