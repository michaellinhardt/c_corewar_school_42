#include "ft_corewar.h"

void		vm_end(t_data *d, t_img *i)
{
	display(&d->mlx, &d->vm);
	(void)d;
	(void)i;
}
