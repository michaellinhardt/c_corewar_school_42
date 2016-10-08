#include "ft_corewar.h"

void	ft_instructions_lld(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	(void)vm;
	(void)inst;
	(void)proc;

	if (proc->wait == inst.cycles)
	{
	if (ft_check_value_args(proc->args, &inst))
	{
		registre = proc->args[1].value;
		if (ft_get_args(proc))
		{
			/*
			*(proc->ireg + registre - 1) = proc->args[0].value;
			proc->carry = !proc->carry;
			*/
			proc->args[1].value = registre;
			proc->last = 3;
			proc->ok = 1;
		}
		else
			proc->carry = 0;
	}
	else
		proc->carry = 0;
	}
	else
	{
		if (proc->ok)
		{

			*(proc->ireg + proc->args[1].value - 1) = proc->args[0].value;
			proc->carry = !proc->carry;
		}
		proc->pc = proc->pc_turfu / 2;
	}

	ft_printf("instruction %s\n", inst.name);
}
