#include "ft_corewar.h"

void	ft_instructions_ld(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst))
	{
		registre = proc->args[1].value;
		if (ft_get_args(proc))
		{
			/*
			if (proc->args[1].value)
				proc->carry = 1;
			else
				proc->carry = 0;
				*/

			*(proc->ireg + registre - 1) = proc->args[0].value % IDX_MOD;
			proc->carry = 0;
			if (proc->args[0].type == DIR_CODE)
				proc->carry = 1;
			else
				proc->carry = 0;



			// MIKA TEST
			if (*(proc->ireg + registre - 1) == 0)
				proc->carry = 1;
			else
				proc->carry = 0;



			/*
				if (proc->last == 2 )
					proc->carry = 1;
				else
					proc->carry = 0;
				proc->last = 2;
				*/
		}
		// else
		// 	proc->carry = 0;
	}
	// else
	// 	proc->carry = 0;
	l2(13, "INSTRUCTION", "instruction ld", proc->id);
	proc->pc = proc->pc_turfu / 2;
//	ft_printf("instruction %s\n", inst.name);
}
