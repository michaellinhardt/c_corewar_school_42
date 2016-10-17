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

static void	ft_skip_bitchies(t_dargs **args, char **argv, t_dvm *vm, int i)
{
	(*args)->file = *(argv + i);
	++args;
	vm->nbr_players++;
}

static int	ft_check_options(t_dvm *vm, int *tab, t_dargs **args, char **argv)
{
	if (!ft_strcmp(*(argv + tab[0]), "-dump"))
	{
		if (tab[0] + 1 >= tab[1])
			return (0);
		vm->dump = ft_atoi(*(argv + ++(tab[0])));
	}
	else if (!ft_strcmp(*(argv + tab[0]), "-n"))
	{
		if (tab[0] + 2 >= tab[1])
			return (0);
		else if (!(ft_get_number_player(&tab[0], argv, args, vm)))
			return (0);
	}
	else if (!ft_strcmp(*(argv + tab[0]), "-v"))
	{
		if (tab[0] + 1 >= tab[1])
			return (0);
		ft_get_show(vm, ft_atoi(*(argv + ++(tab[0]))));
	}
	else
		ft_skip_bitchies(args, argv, vm, tab[0]);
	return (1);
}

int			ft_recup_options(t_dvm *vm, t_dargs *args, char **argv, int argc)
{
	int tab[2];

	tab[0] = 1;
	tab[1] = argc;
	ft_bzero(&(vm->options), sizeof(t_options));
	if (argc == 1)
		return (0);
	while (tab[0] < argc)
	{
		if (!(ft_check_options(vm, tab, &args, argv)))
			return (0);
		if (vm->nbr_players > 4)
			return (0);
		++(tab[0]);
	}
	return (1);
}
