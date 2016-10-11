#include "ft_corewar.h"

int		ft_convert_pc(int pc)
{
	if (pc >= 0)
	{
		/*
		ft_printf("youpi");
		ft_printf("valeur positif de pc %d\n", pc);
		*/
		return (pc);
	}

//	ft_printf("valeur de pc %d\n", pc);
	pc = -(pc) ;
	pc = MEM_SIZE - (pc % 4096);
	return (pc);
}
