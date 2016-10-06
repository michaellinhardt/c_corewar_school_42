/*
** INITIALISE LES EFFET
*/
#include "ft_corewar.h"

void		effect_set(t_effect *e, int effect_id, int start_cycle)
{
	(void)e;
	(void)start_cycle;
	(void)effect_id;
}

t_effect	*effect_data(void)
{
	static t_effect	e[EFFECTS_MAX_SLOT];

	return (e);
}

void		effect_init(t_dmlx *m, t_dvm *v, t_effect *e, int i)
{
	e = effect_data();
	ft_bzero(e, sizeof(e));
	data()->mlx.effect = e;
	e[0].id_max = 1;
	l2(101, "EFFECT_INIT", "(id_max) total of effect", e->id_max);
	while (++i < e->id_max)
		e[i].id_effect = i;
	e[0].looptodie = 100;
	e[0].img = &m->scene_img[2][CPERLOOP_NUMBER];
	l2(101, "EFFECT_INIT", "(scene_img id) CPERLOOP_NUMBER", CPERLOOP_NUMBER);
	(void)v;
}
