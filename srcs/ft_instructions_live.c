#include "ft_corewar.h"

void	ft_instructions_live(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst))
	{
		if (proc->args[0].value > 0 && proc->args[0].value <= vm->nbr_players)
		{
			vm->p[proc->args[0].value].last_cycle_live = vm->cycle;
			vm->p[proc->args[0].value].total_live++;
			vm->nbr_live++;
			vm->last_live = proc->args[0].value;
			proc->live++;
		}
	}
	proc->pc = proc->pc_turfu / 2;
	ft_printf("instruction %s\n", inst.name);
}
