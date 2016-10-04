#include "ft_corewar.h"

void	ft_instructions_fork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc *new;

	(void)vm;
	if (ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
		{
			proc_new(data(), new, proc->player, 0);			
			ft_memcpy(new, proc, sizeof(proc));
			new->pc = (proc->pc + proc->args[0].value % IDX_MOD) % 4096;
		}
	}
	proc->pc = proc->pc_turfu / 2;
	ft_printf("instruction %s\n", inst.name);
}
