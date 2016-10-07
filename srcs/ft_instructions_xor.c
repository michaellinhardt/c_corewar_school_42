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

			// int lol = 0;
			// while (++lol < 6)
				// ft_printf("xor %d ^ 5 = %d\n", lol, lol ^ 5); exit(0);

			ft_printf("[%d] -> r2(%d) ^ %%%d = %d \n", proc->id
			, proc->args[0].value, proc->args[1].value
			, *(proc->ireg + registre - 1));

			// MIKA TESt
			if (*(proc->ireg + registre - 1) == 0)
				proc->carry = 1;
			else
				proc->carry = 0;
			// if (proc->id == 0)
				// ft_printf("xor result: %d\n", *(proc->ireg + registre - 1));


			/*
			if ((proc->args[0].value && proc->args[1].value) ||
			   (!proc->args[0].value && !proc->args[1].value))
				proc->carry = 0;
			else
				proc->carry = 1;
			else
				proc->carry = 0;
			*/
//			proc->carry = !proc->carry;
			proc->last = 8;
//			ft_printf("carry %d\n", proc->carry);
		}
	}
	l2(13, "INSTRUCTION", "instruction xor", proc->id);
	proc->pc = proc->pc_turfu / 2;
//	ft_printf("instruction %s\n", inst.name);
}
