#include "ft_corewar.h"

static int	ft_check_doublons(t_dvm *vm, t_dargs *args, int *nbr)
{
	int i;
	int j;

	i = 0;
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
	return (1);
}

static void	ft_create_number(t_dargs *args, t_dvm *vm, int *nbr)
{
	int i;
	int j;

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
}

int			ft_check_value_number(t_dargs *args, t_dvm *vm)
{
	int i;
	int j;
	int nbr[4];

	nbr[0] = 1;
	nbr[1] = 2;
	nbr[2] = 3;
	nbr[3] = 4;
	i = -1;
	if (!ft_check_doublons(vm, args, nbr))
		exit1(1, data(), "Two players with same number");
	ft_create_number(args, vm, nbr);
	while (++i < vm->nbr_players)
	{
		j = i + 1;
		if (nbr[i] != -1)
			return (0);
		while (j < vm->nbr_players)
		{
			if (args[i].player == args[j].player)
				exit1(1, data(), "Two players with same number");
			++j;
		}
	}
	return (1);
}
