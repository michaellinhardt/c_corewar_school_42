#include "ft_corewar.h"

static void	ft_recup_options_players(t_data *d, char **argv, int argc)
{
	d->args[0].player = -1;
	d->args[1].player = -1;
	d->args[2].player = -1;
	d->args[3].player = -1;
	if (!(ft_recup_options(&d->vm, d->args, argv, argc)))
	{
		ft_printf("erreur ft_recup_options\n");
		exit(1);
	}
	if (d->vm.nbr_players == 0)
		exit(1);
	if (!(ft_check_value_number(d->args, &d->vm)))
	{
		ft_printf("erreur ft_check_value_number\n");
		exit(1);
	}
}

static void	ft_get_init_players(t_data *d)
{
	int		p;

	p = 0;
	ft_printf("Introducing contestants...\n");
	ft_recup_files(&d->vm, d->args);
	ft_recup_headers(&d->vm, d->args);
	ft_recup_code(&d->vm, d->args);
	ft_init_instructions(d->vm.instructions);
	while (p < d->vm.nbr_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		ABS(d->args[p].player), d->vm.p[p].header.prog_size,
		d->vm.p[p].header.prog_name,
		d->vm.p[p].header.comment);
		++p;
	}
}

int			main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	d->mlx.scene = SCENE_START;
	d->vm.dump = -1;
	d->vm.console = CONSOLE_LOG;
	ft_recup_options_players(d, argv, argc);
	ft_get_init_players(d);
	d->vm.graphic = d->vm.dump == -1 ? GRAPHIC_MODE : 0;
	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init()
		&& ascii(ASC_LOG)
	&& d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	return (0);
}
