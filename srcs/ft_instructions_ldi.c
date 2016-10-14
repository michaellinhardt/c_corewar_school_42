#include "ft_corewar.h"

void	ft_instructions_ldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int address;
	int add;
	t_argument argument;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			if (vm->options.operations)
			{
				add = proc->args[0].value + proc->args[1].value;
				ft_printf("P%5d | ldi %d %d r%d\n", proc->id + 1, proc->args[0].value, proc->args[1].value, registre);
				ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", proc->args[0].value, proc->args[1].value, add, (add + proc->pc) % IDX_MOD);
			}
			address = (proc->args[0].value + proc->args[1].value);
			address %= IDX_MOD;
			address *= 2;
			ft_fill_args_dir(&argument, vm, address % SIZE_CHAR_ARENE);
			*(proc->ireg + registre) = argument.value;
		}
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
