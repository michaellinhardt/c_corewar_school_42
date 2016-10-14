#include "ft_corewar.h"

void	ft_instructions_lldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int address;
	t_argument argument;

	(void)vm;
	(void)inst;
	(void)proc;
	registre = 0;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			address = (proc->args[0].value + proc->args[1].value) * 2;
			ft_fill_args_dir(&argument, vm, address);
			if (!(*(proc->ireg + registre - 1) = argument.value))
				proc->carry = 1;
			else
				proc->carry = 0;
		}
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
