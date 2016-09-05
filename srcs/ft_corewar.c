#include "ft_corewar.h"

int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	*argv += 0 * argc; // brain compilateur flag
	/* lance les 4 premiers affichage dans le terminal, puis démarre mlx */
	d->mlx.scene = SCENE_START;
	d->vm.graphic = GRAPHIC_MODE;
	d->vm.console = 1;
	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init() && ascii(ASC_LOG)
	&& d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (43)
			loop_vm(d);
	return (0);
}
