#include "ft_corewar.h"

void	ft_instructions_st(t_dvm *vm, t_instructions inst, t_proc *proc)
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
			ft_printf("valeur dans st a ecrire %u\n", proc->args[1].value);
			if (proc->args[1].type == REG_CODE)
				*(proc->ireg + registre - 1) = proc->args[0].value;
			else
				ft_put_registre(vm->arene, proc->args[0].value,
					   	(proc->args[1].value % IDX_MOD) * 2);
			proc->last = 3;
		}
	}
	l2(13, "INSTRUCTION", "instruction st", proc->id);
	proc->pc = proc->pc_turfu / 2;
//	ft_printf("instruction %s\n", inst.name);
}
