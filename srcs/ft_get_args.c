#include "ft_corewar.h"

int		ft_get_args(t_proc *proc)
{
	int i;

	i = 0;

	while (i < MAX_ARGS_NUMBER)
	{
		if (proc->args[i].type == REG_CODE)
		{
			if (ft_check_reg(proc->args[i].value))
				proc->args[i].value = ft_get_value_registre(proc, proc->args[i].value);
			else
				return (0);
		}
		else if (proc->args[i].type == IND_CODE)
			proc->args[i].value = (proc->args[i].value + proc->pc) % 4096;
		++i;
	}
	return (1);
}
