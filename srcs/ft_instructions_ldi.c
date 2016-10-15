#include "ft_corewar.h"

void	ft_instructions_ldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int address;
	int add;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			if (vm->options.operations)
			{
				add = proc->args[0].value + proc->args[1].value;
				ft_printf("P%5d | ldi %d %d r%d\n", proc->id + 1, proc->args[0].value, proc->args[1].value, registre);
				ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", proc->args[0].value, proc->args[1].value, add, (add + proc->pc));
			}
			address = (proc->args[0].value + proc->args[1].value);
			address %= IDX_MOD;
			address += proc->pc;
			*(proc->ireg + registre - 1) = ft_get_indirect(address, vm);
		}
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
