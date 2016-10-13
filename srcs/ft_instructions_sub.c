#include "ft_corewar.h"

void	ft_instructions_sub(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;

	(void)vm;
	(void)inst;
	(void)proc;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			*(proc->ireg + registre - 1) = proc->args[0].value - proc->args[1].value;
			proc->carry = 0;
		}
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
	l2(13, "INSTRUCTION", "instruction sub", proc->id);


	//	ft_printf("instruction %s\n", inst.name);
}
