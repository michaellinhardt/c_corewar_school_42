#include "ft_corewar.h"

void	ft_instructions_ld(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	(void)vm;
	(void)inst;
	(void)proc;
	l2(13, "INSTRUCTION", "instruction ld", proc->id);

	if (proc->wait == inst.cycles)
	{
		if (ft_check_value_args(proc->args, &inst))
		{
			registre = proc->args[1].value;
			if (ft_get_args(proc))
			{
				proc->args[1].value = registre;
				proc->ok = 1;
			}
		}
	}
	else
	{
		if (proc->ok)
		{
			if ((*(proc->ireg + proc->args[1].value - 1) = proc->args[0].value))
				proc->carry = 0;
			else
				proc->carry = 1;
		}
		else
			proc->carry = 0;
		proc->pc = proc->pc_turfu / 2;
	}
	l2(13, "INSTRUCTION", "instruction ld", proc->id);
	//	ft_printf("instruction %s\n", inst.name);
}
