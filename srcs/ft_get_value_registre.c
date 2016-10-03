#include "ft_corewar.h"

int		ft_get_value_registre(t_proc *proc, int registre)
{
	return (*(proc->ireg + (registre - 1)));
}


int		ft_check_reg(int registre)
{
	if (registre > 0 && registre <= REG_NUMBER)
		return (1);
	return (0);
}
