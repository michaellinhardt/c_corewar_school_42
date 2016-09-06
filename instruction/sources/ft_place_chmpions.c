#include "libft.h"
#include "instructions.h"

void	ft_place_champions(char *vm, t_champion *champions, int champs)
{
	while (champs)
	{
		ft_memmove(vm, champions->prog_size, CHAMP_MAX_SIZE);
		--champs;
	}
}
