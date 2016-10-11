#include "ft_corewar.h"

void	ft_instructions_zjmp(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	if (proc->ok)
		return ;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			if (proc->carry)
			{
				if (vm->options.operations)
					ft_printf("P%5d | zjmp %d OK\n", proc->id + 1, proc->args[0].value);
				proc->pc += (int)proc->args[0].value;
			}
			else
			{
				if (vm->options.operations)
					ft_printf("P%5d | zjmp %d FAILURE\n", proc->id + 1, proc->args[0].value);
				proc->pc = proc->pc_turfu / 2;
			}
		}
		else
			proc->pc = proc->pc_turfu / 2;
	}
	else
		proc->pc = proc->pc_turfu / 2;
	l2(13, "INSTRUCTION", "instruction zjmp", proc->id);
	//ft_printf("instruction %s\n", inst.name);
}
