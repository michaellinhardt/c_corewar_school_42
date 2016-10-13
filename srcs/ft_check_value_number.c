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


