#include "ft_asm.h"
#include "libft.h"

/*
**			Retourne l'id de l'instruction si ok
*/

int			ft_check_name_instructions(char *instruction, t_instructions *inst)
{
	int i;

	i = 1;
	while (i < NBR_INST)
	{
		if (!ft_strcmp(instruction, inst[i].name))
			return (i);
		++i;
	}
	return (0);
}
