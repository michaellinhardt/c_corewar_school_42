#include "ft_corewar.h"

void	ft_instructions_zjmp(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	//		ft_printf("proc->id%d\n", proc->id);
	if (proc->carry && ft_check_value_args(proc->args, &inst))
	{
	//	ft_putnbr(proc->carry);
		if (ft_get_args(proc))
		{
			proc->pc += (int)proc->args[0].value;
			proc->last = 9;
//			proc->carry = 0;
		}
		else
			proc->pc = proc->pc_turfu / 2;
	}
	else
		proc->pc = proc->pc_turfu / 2;

	l2(13, "INSTRUCTION", "instruction zjmp", proc->id);
	//ft_printf("instruction %s\n", inst.name);
}
