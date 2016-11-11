/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:42 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:42 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	ft_recup_options_players(t_data *d, char **argv, int argc)
{
	d->args[0].player = -1;
	d->args[1].player = -1;
	d->args[2].player = -1;
	d->args[3].player = -1;
	if (!(ft_recup_options(&d->vm, d->args, argv, argc)))
		exit1(1, d, "Missing options, use -h for help");
	if (d->vm.nbr_players == 0)
		exit1(1, d, "No players: ex ./corewar [options] /path/players");
	if (!(ft_check_value_number(d->args, &d->vm)))
		exit1(1, d, "Two players with same number");
}

static void	ft_get_init_players(t_data *d)
{
	int		p;

	p = 0;
	if (!d->vm.console)
		ft_printf("Introducing contestants...\n");
	ft_recup_files(&d->vm, d->args);
	ft_recup_headers(&d->vm, d->args);
	ft_recup_code(&d->vm, d->args);
	ft_init_instructions(d->vm.instructions);
	while (p < d->vm.nbr_players)
	{
		if (!d->vm.console)
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
	d->vm.dump = -1;
	d->vm.console = CONSOLE_LOG;
	d->vm.graphic = d->vm.dump == -1 ? GRAPHIC_MODE : 0;
	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init())
		ascii(ASC_LOG);
	ft_recup_options_players(d, argv, argc);
	ft_get_init_players(d);
	if (!d->vm.graphic)
		d->mlx.scene = VM_INIT;
	if (d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	return (0);
}
