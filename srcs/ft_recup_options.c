#include "ft_corewar.h"

int		ft_check_value_number(t_dargs *args, t_dvm *vm)
{
	int i;
	int j;
	int nbr[4];

	nbr[0] = 1;
	nbr[1] = 2;
	nbr[2] = 3;
	nbr[3] = 4;
	i = 0;
	// verif pas de doublons
	while (i < vm->nbr_players)
	{
		if (args[i].player != -1)
		{	
			j = i + 1;
			while (j < vm->nbr_players)
			{
				if (args[i].player == args[j].player)
						return (0);
				++j;
			}
			nbr[args[i].player - 1] = -1;	
		}
		++i;
	}
	// attributions des nums manquants
	i = 0;
	while (i < vm->nbr_players)
	{
		if (args[i].player == -1)
		{
			j = 0;
			while (j < 4)
			{
				if (nbr[j] != -1)
				{
					args[i].player = nbr[j];
					nbr[j] = -1;
					break ;
				}
				++j;
			}	
		}
		++i;
	}
	// verif pas de doublons"
	i = 0;
	while (i < vm->nbr_players)
	{
		j = i + 1;
		if (nbr[i] != -1)
			return (0);
		while (j < vm->nbr_players)
		{
			if (args[i].player == args[j].player)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static void	ft_get_show(t_dvm *vm, int options)
{
	vm->options.lives = (options & 1) == 1;
	vm->options.cycles = (options & 2) == 2;
	vm->options.operations = (options & 4) == 4;
	vm->options.deaths = (options & 8) == 8;
	vm->options.movements = (options & 16) == 16;

	/*
	if (vm->options.lives)
		ft_putendl("option lives");
	if (vm->options.cycles)
		ft_putendl("option cyles");
	if (vm->options.operations)
		ft_putendl("option operations");
	if (vm->options.deaths)
		ft_putendl("option deaths");
	if (vm->options.movements)
		ft_putendl("option movements");
		*/
}

int 	ft_recup_options(t_dvm *vm, t_dargs *args, char **argv, int argc)
{
	ft_bzero(&(vm->options), sizeof(t_options));
	int i;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!ft_strcmp(*(argv + i), "-dump"))
		{
			if (i + 1 >= argc)
				return (0);
			vm->dump = ft_atoi(*(argv + ++i));
		}
		else if (!ft_strcmp(*(argv + i), "-n"))
		{
			if (i + 2 >= argc)
				return (0);
			else
			{
				args->player = ft_atoi(*(argv + ++i));
				if (args->player < 1 || args->player > 4)
					return (0);
				args->file = *(argv + ++i);
				++args;
				vm->nbr_players++;
			}
		}
		else if (!ft_strcmp(*(argv + i), "-v"))
		{
			if (i + 1 >= argc)
				return (0);
			ft_get_show(vm, ft_atoi(*(argv + ++i)));
		}
		else
		{
			ft_printf("argument : %s\n", *(argv + i));
			args->file = *(argv + i);
			++args;
			vm->nbr_players++;
		}
		if (vm->nbr_players > 4)
			return (0);
		++i;
	}
	return (1);
}
