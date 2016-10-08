#include "ft_corewar.h"

#include <stdio.h>

void	ft_instructions_st(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int convert;

	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst))
	{
		registre = proc->args[1].value;
		convert = ft_convert_pc(proc->args[1].value);
		proc->args[1].value = convert % IDX_MOD;
		if (ft_get_args(proc))
		{
			if (proc->args[1].type == REG_CODE)
				*(proc->ireg + registre - 1) = proc->args[0].value;
			else
			{
				ft_put_registre(vm->arene, (unsigned int)proc->args[0].value,
					   	(proc->pc + convert) * 2);
				ft_put_color_size(vm->color, vm->code_color[-proc->player],
						proc->pc + convert, 4);
			}
			proc->last = 3;
		}
	}
	l2(13, "INSTRUCTION", "instruction st", proc->id);
	proc->pc = proc->pc_turfu / 2;
//	ft_printf("instruction %s\n", inst.name);
}
