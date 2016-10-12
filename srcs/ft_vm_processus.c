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
	l1(-1, "PROC NEW", "*** NEW PROC ***");
	setid = 0;
	if (d->vm.procdie && (new = d->vm.procdie)
	&& (((setid = d->vm.procdie->id) || 1))
	&& ((d->vm.procdie = d->vm.procdie->n) || 1)
	&& ((d->vm.procdie && ((d->vm.procdie->p = (t_proc *)NULL) || 1)) || 1))
		l2(-1, "PROC RESURECT", "id", setid);
	else if ((((setid = ++id) || 1)) && l2(-1, "PROC MALLOC", "id", setid)
	&& !(new) && !(new = (t_proc *)ft_memalloc(sizeof(t_proc))))
		exit1(1, data(), "Can't malloc struct s_proc");


	ft_bzero(new, sizeof(new));
	// positionne le processus dans la liste d->proc à l'endroit ou il devrait
	// se trouver (avec les liens next et previous correspondant)
	if (d->vm.proc && (new->n = d->vm.proc))
		(d->vm.proc)->p = new;
	else
		new->n = (t_proc *)NULL;
	new->p = (t_proc *)NULL;
	d->vm.proc = new;

	// positionne par rapprot a l'id pour un ordre decroissant

	/*
	t_proc *begin;
	t_proc *tmp;

	begin = d->vm.proc;
	while (begin && begin->id < )
	{
		tmp = begin;
		begin = begin->n;
	}
	*/
	// régle les valeur du proc
	//
	new->ireg = (int *)new->reg;
	new->ireg[0] = player;
	new->player = player;
	new->pc = i;
	new->id = setid;
	new->last_live = data()->vm.cycle;
	new->create_cycle = data()->vm.cycle;
	//ft_printf("New Process id :%d\n", new->id);
//	ft_printf("new process :%d, cycle %d\n", new->id, d->vm.cycle);
//	ft_putchar('\n');
	d->vm.nbr_proc++;
	// ft_printf("%d\n", player);
	// ft_printf("%d\n", ABS(player));
	d->vm.p[(ABS(player)) - 1].total_proc_alive++;
	// ft_printf("%d\n", (ABS(player) - 1)); exit(0);
	/*
	l2(-1, "PROC SETTINGS", "player attribution", player);
	l2(-1, "PROC SETTINGS", "id processus", setid);
	l2(-1, "PROC SETTINGS", "cycle", data()->vm.cycle);
	*/
}

/*
** FONCTION QUI TUE LES PROCESS ET LES PLACE DAnS LA LISTE MORTE
*/
int		proc_kill(t_data *d, t_proc *target, t_proc *procdie)
{
	target->DIE_MF = 1;
	if ((d)->vm.options.deaths)
	ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			target->id + 1, d->vm.cycle - target->last_live, d->vm.ctodie);
//	ft_printf("kill process : %d, cycle : %d nbr live %d\n",
//		   	target->id, d->vm.cycle,
//			target->live);
/*
	l2(-1, "PROC KILL", "id processus -> KILL", target->id);
	l2(-1, "PROC KILL", "(create cycle)", target->create_cycle);
	*/
	//ft_printf("New Process id :%d\n", target->id);
	(void)d;
	(void)target;
	(void)procdie;
	if (target->p)
		target->p->n = target->n;

	if (target->n)
		target->n->p = target->p;
	if (d->vm.proc == target)
		d->vm.proc = target->n;
	d->vm.p[(ABS(target->player)) - 1].total_proc_alive--;
	d->vm.p[(ABS(target->player)) - 1].total_proc_dead--;
	target->n = 0;
	target->p = 0;
	free (target);
	target = 0;
	// déplace le maillon
	/*
	if (procdie && (target->n = procdie))
		procdie->p = target;
	data()->vm.procdie = target;
	target->p = (t_proc *)NULL;
	*/
	d->vm.nbr_proc--;
	return (1);
}
