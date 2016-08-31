/*
** GESTION DES PROCESSUS
*/
#include "ft_corewar.h"

void	proc_new(t_dvm *v, t_proc *new, int player, int i)
{
	// FONCTION QUI RECUPERE UN PROCESSUS MORT OU EN CREER UN NOUVEAU
	static int	id = -1;

	// Récupére un proc mort si il existe, sinon le créer
	if (v->procdie && (new = v->procdie)
	&& (v->procdie = v->procdie->n) && v->procdie)
		v->procdie->p = (t_proc *)NULL;
	else if (!(new) && !(new = (t_proc *)ft_memalloc(sizeof(t_proc))))
		exit1(1, data(), "Can't malloc struct s_proc");

	// positionne le nouveau proc dans la liste
	new->p = (t_proc *)NULL;
	new->n = v->proc;
	v->proc = new;

	// régle les valeur du proc
	new->player = player;
	new->i = i;
	new->id = ++id;
	l2(12, "NEW PROC", "id", id);
	l2(12, "NEW PROC", "player", player);
	l2(12, "NEW PROC", "start value", i);
}
