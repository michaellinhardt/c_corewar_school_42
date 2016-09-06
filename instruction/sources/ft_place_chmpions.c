#include "libft.h"
#include "instructions.h"

void	ft_place_champions(char *vm, t_champion *champions, int champs)
{
	unsigned int nbr;

	nbr = 0;
	while (nbr < champs)
	{
		/*
		ft_putnbr(nbr % MEM_SIZE);
		ft_putendl("");
		*/
		ft_memmove(vm + ((nbr * MEM_SIZE) / champs), champions->prog_size, CHAMP_MAX_SIZE);
		++champions;
		++nbr;
	}
}
