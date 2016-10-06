/*
** INITIALISE LES EFFET
*/
#include "ft_corewar.h"

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

	e[0].img = &m->scene_img[2][CPERLOOP_NUMBER];
	e[0].size_x = EFFECT_CPERLOOP_X;
	e[0].size_y = EFFECT_CPERLOOP_Y;
	e[0].x = EFFECT_CPERLOOP_WIN_X;
	e[0].y = EFFECT_CPERLOOP_WIN_Y;
	l2(101, "EFFECT_INIT", "scene_img[2][CPERLOOP_NUMBER]", CPERLOOP_NUMBER);
	l2(101, "EFFECT_INIT", "(looptodie) time to display effect"
		, (e[0].looptodie_count = EFFECT_CPERLOOP_TODIE));
	l2(101, "EFFECT_INIT", "(inc_value) fade incrementation"
		, (e[i].inc_value = 255 / e[0].looptodie_count));

	l2(101, "EFFECT_INIT", "(id_max) total of effect", e->id_max);

	while (++i < e->id_max)
		e[i].id_effect = i;

	(void)v;
}
