#include "ft_corewar.h"

void	vm_end_shadow(t_img *i)
{
	static int	fade = 255;

	if (fade > 150)
	{
		fade -= VM_FADEOUT_SPEED;
		i->i = -4;
		while ((i->i += 4) < (i->sl * WIN_Y))
			i->str[i->i + 3] = fade;
	}
	itow(i->img, 0, 0, "fade in");
}

void		vm_end(t_data *d, t_img *i)
{
	display(&d->mlx, &d->vm);
	vm_end_shadow(i);
}
