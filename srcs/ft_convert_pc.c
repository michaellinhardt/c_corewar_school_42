#include "ft_corewar.h"

int		ft_convert_pc(int pc)
{
	if (pc >= 0)
		return (pc % MEM_SIZE);
	while (pc < 0)
	{
		pc = -(pc);
		pc = MEM_SIZE - pc;
	}
	return (pc % MEM_SIZE);
}
