#include "ft_corewar.h"

int		ft_get_args(t_proc *proc)
{
	int i;

	i = -1;
	while (++i < proc->inst->nbr_args)
	{
		if (proc->args[i].type == REG_CODE)
		{
			if (ft_check_reg(proc->args[i].value))
				proc->args[i].value = ft_get_value_registre(proc, proc->args[i].value);
			else
				return (0);
		}
		else if (proc->args[i].type == IND_CODE && proc->inst->id != 13 && 
				proc->inst->id != 14)
		{
			proc->args[i].value = (proc->args[i].value ) % IDX_MOD;
			proc->args[i].value = ft_convert_pc(proc->args[i].value);
			proc->args[i].value = (proc->args[i].value + proc->pc);
		}
		else if (proc->args[i].type == IND_CODE)
			proc->args[i].value = (proc->args[i].value + proc->pc);
	}
	return (1);
}
