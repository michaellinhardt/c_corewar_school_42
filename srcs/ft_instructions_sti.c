#include "ft_corewar.h"

void	ft_instructions_sti(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int address;
	(void)vm;
	(void)inst;
	(void)proc;

	if (ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
		{
			address = (proc->args[1].value + proc->args[2].value + proc->pc) * 2;
			ft_put_registre(vm->arene, proc->args[0].value , address );
			ft_put_color_size(vm->color, vm->code_color[proc->player],
				   	address / 2, 4);
			proc->last = 11;
		}
	}
	l1(13, "INSTRUCTION", "instruction sti");
	proc->pc = proc->pc_turfu / 2;
//	ft_printf("instruction %s\n", inst.name);
}
