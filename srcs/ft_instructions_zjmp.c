#include "ft_corewar.h"

void	ft_instructions_zjmp(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	if (proc->wait == inst.cycles)
	{
	if (proc->carry && ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
		{
			proc->ok = 1;
			proc->last = 9;
		}
	}
	}
	else
	{
		if (proc->ok)
			proc->pc += (int)proc->args[0].value;
		else
			proc->pc = proc->pc_turfu / 2;
	}
	l2(13, "INSTRUCTION", "instruction zjmp", proc->id);
	//ft_printf("instruction %s\n", inst.name);
}
