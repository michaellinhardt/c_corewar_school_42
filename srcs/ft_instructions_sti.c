#include "ft_corewar.h"

void	ft_instructions_sti(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int convert1;
	int convert2;
	int registre;
	int add;
	(void)vm;
	(void)inst;
	(void)proc;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[0].value;
		if (ft_get_args(proc))
		{
			add = proc->args[1].value + proc->args[2].value;
			if (vm->options.operations)
			{
				ft_printf("P%5d | sti r%d %d %d\n", proc->id + 1, registre, proc->args[1].value, proc->args[2].value);
				ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", proc->args[1].value, proc->args[2].value, add, add + proc->pc);
			}
			convert1 = ft_convert_pc(proc->args[1].value);
			convert2 = ft_convert_pc(proc->args[2].value);

			int address;
			if (proc->args[1].type == IND_CODE)
				address = (convert1 + convert2 ) * 2;
			else
				address = (convert1 + convert2 + proc->pc) * 2;
			ft_put_registre(vm->arene, proc->args[0].value , address);
			ft_put_color_size(vm->color, ARENE_CODE_COLOR_P2,
					address / 2, 4);
		}
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
	l2(13, "INSTRUCTION", "instruction sti", proc->id);
	//	ft_printf("instruction %s\n", inst.name);
}
