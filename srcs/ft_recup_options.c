#include "ft_corewar.h"

static void	ft_get_show(t_dvm *vm, int options)
{
	vm->options.lives = (options & 1) == 1;
	vm->options.cycles = (options & 2) == 2;
	vm->options.operations = (options & 4) == 4;
	vm->options.deaths = (options & 8) == 8;
	vm->options.movements = (options & 16) == 16;
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
