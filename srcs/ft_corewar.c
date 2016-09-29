#include "ft_corewar.h"

int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	*argv += 0 * argc; // brain compilateur flag
	/* lance les 4 premiers affichage dans le terminal, puis démarre mlx */
	d->mlx.scene = SCENE_START;
	d->vm.graphic = GRAPHIC_MODE;
	d->vm.console = CONSOLE_LOG;

	// parse options + champs;
	ft_recup_files(&d->vm, &d->args, argv, argc);
	ft_recup_headers(&d->vm, &d->args);
	ft_recup_code(&d->vm, &d->args);

	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init()
		&& ascii(ASC_LOG)
	&& d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	return (0);
}
