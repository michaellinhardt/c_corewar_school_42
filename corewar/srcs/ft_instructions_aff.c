#include "ft_corewar.h"

void	ft_instructions_aff(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			log_inst(proc->player, proc->id, "AFF");
			ft_printf("Aff: %c\n", proc->args[0].value % 256);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
