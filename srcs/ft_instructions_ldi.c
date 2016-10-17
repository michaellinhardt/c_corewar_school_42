#include "ft_corewar.h"

void	ft_instructions_ldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int address;
	int result;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
				address = (proc->args[0].value + proc->args[1].value);
				result = address % 512;
				result += proc->pc;
			if (vm->options.operations)
			{
				ft_printf("P%5d | ldi %d %d r%d\n", proc->id + 1, proc->args[0].value, proc->args[1].value, registre);
				ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", proc->args[0].value, proc->args[1].value, address, 
						result);
			}
			address %= IDX_MOD;
			address += proc->pc;
			*(proc->ireg + registre - 1) = ft_get_indirect(address, vm);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
	  	proc->pc %= MEM_SIZE;
	//proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
