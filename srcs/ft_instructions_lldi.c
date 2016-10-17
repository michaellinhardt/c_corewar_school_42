#include "ft_corewar.h"

void	ft_instructions_lldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int address;
	int result;

	(void)vm;
	(void)inst;
	(void)proc;
	registre = 0;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			address = (proc->args[0].value + proc->args[1].value);
			result = address + proc->pc % MEM_SIZE;
			if (vm->options.operations)
			{
				if (proc->id < 10000)
					ft_printf("P%5d | lldi %d %d r%d\n", proc->id, proc->args[0].value, proc->args[1].value, registre);
				else if (proc->id < 100000)
					ft_printf("P%6d | lldi %d %d r%d\n", proc->id, proc->args[0].value, proc->args[1].value, registre);
				else
					ft_printf("P%7d | lldi %d %d r%d\n", proc->id, proc->args[0].value, proc->args[1].value, registre);
				ft_printf("       | -> load from %d + %d = %d (with pc %d)\n", proc->args[0].value, proc->args[1].value, address, 
						result);
			}
			address += proc->pc;
			if (!(*(proc->ireg + --registre) = ft_get_indirect(address, vm)))
				proc->carry = 1;
			else
				proc->carry = 0;
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
