#include "ft_corewar.h"

int		ft_check_value_args(t_argument *args, t_instructions *inst)
{
	int i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (args[i].type == REG_CODE && ((0x01 & inst->types[i]) != 0x01))
		{
			ft_printf("REG CODE %d\n", i);
			return (0);
		}
		else if (args[i].type == DIR_CODE  && ((0x02 & inst->types[i]) != 0x02))
		{
			ft_printf("DIR CODE %d\n", i);
			return (0);
		}
		else if (args[i].type == IND_CODE  && ((0x04 & inst->types[i]) != 0x04))
		{
			ft_printf("IND CODE %d\n", i);
			return (0);
		}
		++i;
	}
	return (1);
}
