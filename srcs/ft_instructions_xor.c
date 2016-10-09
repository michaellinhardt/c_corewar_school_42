#include "ft_corewar.h"

void	ft_instructions_xor(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;

	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			if ((*(proc->ireg + registre - 1) =
						proc->args[0].value ^ proc->args[1].value))
				proc->carry = 0;
			else
				proc->carry = 1;

			proc->ok = 1;
			proc->last = 8;
		}
	}
	proc->pc = proc->pc_turfu / 2;
	l2(13, "INSTRUCTION", "instruction xor", proc->id);
	//	ft_printf("instruction %s\n", inst.name);
}
