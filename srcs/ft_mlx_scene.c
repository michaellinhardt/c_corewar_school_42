#include "ft_corewar.h"
/*
 * Le routage de la scene en cours se fait par ici
 */

void		scene(t_data *d, t_dmlx *m, t_input *i)
{
	d->mlx.loop += 0 * i->left * m->loop;
	(m->scene == INTRO) ? scene_intro(d, m, i) : 0;
	(m->scene == VM_INIT) ? vm_init(d, &d->vm, MAX_PLAYERS) : 0;
	(m->scene == VM) ? vm(&d->vm, CYCLE_PER_LOOP) : 0;
}
