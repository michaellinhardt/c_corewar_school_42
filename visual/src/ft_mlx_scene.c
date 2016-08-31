#include "ft_corewar.h"
/*
 * Le routage de la scene en cours se fait par ici
 */

void		scene(t_data *d, t_dmlx *m, t_input *i)
{
	d->mlx.loop += 0 * i->left * m->loop;
	// (m->scene == INTRO) ? intro() : 0;
}
