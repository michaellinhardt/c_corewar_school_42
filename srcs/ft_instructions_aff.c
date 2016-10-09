#include "ft_corewar.h"

void	ft_instructions_aff(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
		if (ft_check_value_args(proc->args, &inst, vm, proc))
		{
			if (ft_get_args(proc))
			{
				ft_putchar(proc->args[0].value % 256);
				proc->last = 16;
			}
		}
	proc->pc = proc->pc_turfu / 2;
	l2(13, "INSTRUCTION", "instruction aff", proc->id);

	//	ft_printf("instruction %s\n", inst.name);
}
