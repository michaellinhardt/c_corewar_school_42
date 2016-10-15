#include "ft_corewar.h"

void	ft_instructions_zjmp(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			if (proc->carry)
			{
				if (vm->options.operations)
					ft_printf("P%5d | zjmp %d OK\n", proc->id + 1, proc->args[0].value);
				proc->args[0].value %= IDX_MOD;
				proc->pc += (int)proc->args[0].value;
				proc->pc = ft_convert_pc(proc->pc);
				proc->pc %= MEM_SIZE;
				return ;
			}
			else
			{
				if (vm->options.operations)
					ft_printf("P%5d | zjmp %d FAILED\n", proc->id + 1, proc->args[0].value);
	//			proc->pc = proc->pc_turfu / 2;
		//		proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
			}
		}
	//	else
//	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
	//		proc->pc = proc->pc_turfu / 2;
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
	//	proc->pc = proc->pc_turfu / 2;
}
