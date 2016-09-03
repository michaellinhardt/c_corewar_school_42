#include "ft_corewar.h"
/*
 * Gestion de la scene INTRO
 */

void		scene_intro(t_data *d, t_dmlx *m, t_input *i)
{
	d->mlx.loop += 0 * i->left * m->loop;
	// (m->scene == INTRO) ? scene_intro() : 0;
	ft_printf("ok\n");
	exit (0);
}
