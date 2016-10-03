#include "ft_corewar.h"

void	ft_instructions_and(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
		{
			proc->args[2].value = proc->args[0].value & proc->args[1].value;
			proc->carry = 1;
		}
		else
			proc->carry = 0;
	}
	else
		proc->carry = 0;
	proc->pc = proc->pc_turfu / 2;
	ft_printf("instruction %s\n", inst.name);
}
