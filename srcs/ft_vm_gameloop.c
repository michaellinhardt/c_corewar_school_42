#include "ft_corewar.h"

static void		ft_kill_dead_process(t_proc *p)
{
	t_proc	*next;

	next = 0;
	while (p)
	{
		if (p->live < 1)
		{
			next = p->n;
			proc_kill(data(), p);
			if (next)
			{
				p = next;
				continue;
			}
			else
				break ;
		}
		if (p)
		{
			p->live = 0;
			p->live_player = 0;
		}
		p = p->n;
	}
}

static int		ft_checklive(t_dvm *v, t_proc *p)
{
	int palive;

	ft_kill_dead_process(p);
	v->ctodiecount = 0;
	v->max_checks++;
	if (v->nbr_live >= NBR_LIVE)
	{
		v->max_checks = 0;
		v->ctodie = v->ctodie - CYCLE_DELTA;
		if (v->options.cycles)
			ft_printf("Cycle to die is now %d\n", v->ctodie);
	}
	else if (((v->max_checks >= MAX_CHECKS)))
	{
		v->max_checks = 0;
		v->ctodie = v->ctodie - CYCLE_DELTA;
		if (v->options.cycles)
			ft_printf("Cycle to die is now %d\n", v->ctodie);
	}
	palive = v->nbr_live;
	v->nbr_live = 0;
	v->live_player = 0;
	return (palive);
}

int				gameloop(t_dvm *v)
{
	int ret;

	ret = 0;
	processus_read(v, v->proc);
	++(v->ctodiecount);
	if (v->ctodiecount >= v->ctodie
			&& !(ret = ft_checklive(v, v->proc)))
		return (0);
	return (1);
}
