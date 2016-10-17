#include "ft_corewar.h"

void	ft_instructions_aff(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			ft_printf("Aff: "YELLOW"<%hhX>"NEUTRE"\n", proc->args[0].value % 256);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
