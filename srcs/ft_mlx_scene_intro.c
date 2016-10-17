#include "ft_corewar.h"

void		scene_intro(t_data *d, t_dmlx *m, t_input *i)
{
	d->mlx.loop += 0 * i->left * m->loop;
	ft_printf("ok\n");
	exit(0);
}
