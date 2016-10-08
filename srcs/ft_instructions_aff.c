#include "ft_corewar.h"

void	ft_instructions_aff(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	if (proc->wait == inst.cycles)
	{
		if (ft_check_value_args(proc->args, &inst))
		{
			if (ft_get_args(proc))
			{
				proc->args[0].value = proc->args[0].value % 256;
	//			ft_putchar(proc->args[0].value % 256);
				proc->last = 16;
				proc->ok = 1;
			}
		}
	}
	else
	{
		if (proc->ok)
			ft_putchar(proc->args[0].value);
	proc->pc = proc->pc_turfu / 2;
	}
	l2(13, "INSTRUCTION", "instruction aff", proc->id);

	//	ft_printf("instruction %s\n", inst.name);
}
