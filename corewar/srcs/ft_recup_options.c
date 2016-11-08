#include "ft_corewar.h"

static void	ft_get_show(t_dvm *vm, int options)
{
	vm->options.lives = (options & 1) == 1;
	vm->options.cycles = (options & 2) == 2;
	vm->options.operations = (options & 4) == 4;
	vm->options.deaths = (options & 8) == 8;
	vm->options.movements = (options & 16) == 16;
}

static int	ft_get_number_player(int *i, char **argv, t_dargs **args, t_dvm *vm)
{
	(*args)->player = ft_atoi(*(argv + ++(*i)));
	if ((*args)->player < 1 || (*args)->player > 4)
		return (0);
	(*args)->file = *(argv + ++(*i));
	++(*args);
	vm->nbr_players++;
	return (1);
}

static void	ft_check_options2(t_dvm *vm, int *tab, t_dargs **args, char **argv)
{
	if (!ft_strcmp(*(argv + tab[0]), "-g"))
		vm->graphic = 1;
	else if (!ft_strcmp(*(argv + tab[0]), "-i"))
		data()->mlx.scene = VM_INIT;
	else if (!ft_strcmp(*(argv + tab[0]), "-c"))
		vm->color_proc = 1;
	else if (!ft_strcmp(*(argv + tab[0]), "-p"))
		vm->pause = 1;
	else if (!ft_strcmp(*(argv + tab[0]), "-l"))
		vm->consolee = 1;
	else if (!ft_strcmp(*(argv + tab[0]), "-h"))
		ft_display_help();
	else if (!ft_strcmp(*(argv + tab[0]), "-m"))
		data()->mlx.sound = 1;
	else if (!ft_strcmp(*(argv + tab[0]), "-ff7"))
		data()->mlx.sound = 2;
	else
	{
		(*args)->file = *(argv + tab[0]);
		++*args;
		vm->nbr_players++;
	}
}

static void	ft_check_options(t_dvm *vm, int *tab, t_dargs **args, char **argv)
{
	if (!ft_strcmp(*(argv + tab[0]), "-dump"))
	{
		if (tab[0] + 1 >= tab[1])
			exit1(1, data(), "Missing dump value");
		vm->dump = ft_atoi(*(argv + ++(tab[0])));
	}
	else if (!ft_strcmp(*(argv + tab[0]), "-n"))
	{
		if (tab[0] + 2 >= tab[1])
			exit1(1, data(), "Missing player number value or file with -n");
		else if (!(ft_get_number_player(&tab[0], argv, args, vm)))
			exit1(1, data(), "Player number can only be beetwin 1 and 4");
	}
	else if (!ft_strcmp(*(argv + tab[0]), "-v"))
	{
		if (tab[0] + 1 >= tab[1])
			exit1(1, data(), "Missing verbose value with -v");
		ft_get_show(vm, ft_atoi(*(argv + ++(tab[0]))));
	}
	else
		ft_check_options2(vm, tab, args, argv);
}

int			ft_recup_options(t_dvm *vm, t_dargs *args, char **argv, int argc)
{
	int		tab[2];

	tab[0] = 1;
	tab[1] = argc;
	ft_bzero(&(vm->options), sizeof(t_options));
	if (argc == 1)
		return (0);
	while (tab[0] < argc)
	{
		ft_check_options(vm, tab, &args, argv);
		if (vm->nbr_players > 4)
			exit1(1, data(), "To many players or bad options");
		(tab[0])++;
	}
	if (vm->consolee && !vm->console && (vm->console = 1) && ascii(ASC_LOGO)
	&& ascii(ASC_INIT) && ascii_init())
		ascii(ASC_LOG);
	return (1);
}
