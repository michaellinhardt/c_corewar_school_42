#include "ft_corewar.h"

void	ft_instructions_ld(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	(void)vm;
	(void)inst;
	(void)proc;
	l2(13, "INSTRUCTION", "instruction ld", proc->id);

	if (ft_check_value_args(proc->args, &inst))
	{
		if (proc->id == 6)
		{
			ft_printf("valeur charger dans le registre :%d\n",
					proc->args[0].value);
		}
		//	ft_printf("proc->id : %d\n", proc->id);
		registre = proc->args[1].value;
		if (ft_get_args(proc))
		{
			if ((*(proc->ireg + registre - 1) = proc->args[0].value))
				proc->carry = 0;
			else
				proc->carry = 1;
		}
	}
proc->pc = proc->pc_turfu / 2;
l2(13, "INSTRUCTION", "instruction ld", proc->id);
//	ft_printf("instruction %s\n", inst.name);
}
