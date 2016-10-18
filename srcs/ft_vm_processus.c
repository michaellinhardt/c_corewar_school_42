#include "ft_corewar.h"

void	proc_new(t_data *d, t_proc *new, int player, int i)
{
	static int	id = 0;

	++id;
	if (!(new = (t_proc *)ft_memalloc(sizeof(t_proc))))
		exit1(1, data(), "Can't malloc struct s_proc");
	new->p = (t_proc *)NULL;
	if (d->vm.proc && (new->n = d->vm.proc))
		(d->vm.proc)->p = new;
	else
		new->n = (t_proc *)NULL;
	d->vm.proc = new;
	new->ireg = (int *)new->reg;
	new->ireg[0] = player;
	new->player = player;
	new->pc = i;
	new->id = id;
	new->last_live = data()->vm.cycle;
	new->create_cycle = data()->vm.cycle;
	d->vm.nbr_proc++;
	d->vm.p[(ABS(player)) - 1].total_proc_alive++;
}

int		proc_kill(t_data *d, t_proc *target)
{
	if ((d)->vm.options.deaths)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				target->id, d->vm.cycle - target->last_live, d->vm.ctodie);
	if (target->p)
		target->p->n = target->n;
	if (target->n)
		target->n->p = target->p;
	if (d->vm.proc == target)
		d->vm.proc = target->n;
	d->vm.p[(ABS(target->player)) - 1].total_proc_alive--;
	d->vm.p[(ABS(target->player)) - 1].total_proc_dead++;
	target->n = 0;
	target->p = 0;
	free(target);
	target = 0;
	d->vm.nbr_proc_dead++;
	d->vm.nbr_proc--;
	return (1);
}
