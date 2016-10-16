#include "ft_corewar.h"

void	ft_instructions_or(t_dvm *vm, t_instructions inst, t_proc *proc)
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
			if (vm->options.operations)
				ft_printf("P%5d | or %d %d r%d\n", proc->id + 1, proc->args[0].value, proc->args[1].value, registre);
			if ((*(proc->ireg + registre - 1)
						= proc->args[0].value | proc->args[1].value))
				proc->carry = 0;
			else
				proc->carry = 1;
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
	  	proc->pc %= MEM_SIZE;
	//proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
