#include "ft_corewar.h"


void	wip(t_data *d)
{
	d->args.file[4] = (char *)NULL;

	d->args.file[0] = "./zaz/bee_gees.cor";
	d->args.file[1] = (char *)NULL;
}




int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	*argv += 0 * argc; // brain compilateur flag
	/* lance les 4 premiers affichage dans le terminal, puis démarre mlx */
	d->mlx.scene = SCENE_START;
	d->vm.graphic = GRAPHIC_MODE;
	d->vm.console = CONSOLE_LOG;


	wip(d);



	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init()
		&& ascii(ASC_LOG)
	&& d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	return (0);
}
