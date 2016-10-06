/*
** GENERE LES EFFET
*/
#include "ft_corewar.h"

void	display_effect(t_dmlx *m, t_dvm *v, t_effect *e, int i)
{
	(void)m;
	(void)v;
	while (++i < e->id_max)
		if (e->looptodie > 0 && --e->looptodie && e->start_cycle >= v->cycle)
		{
			if (e->id_effect == 1 && loop(1))
				l2(101, "EFFECT_PRINT", "(id_effect) is active", e->id_effect);
			else
				break ;
		}
}
