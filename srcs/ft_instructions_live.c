#include "ft_corewar.h"

#define ABS(x) x < 0 ? -x : x
void	ft_instructions_live(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	(void)vm;
	(void)inst;
	(void)proc;

	if (ft_check_value_args(proc->args, &inst))
	{
		if (proc->args[0].value <= -1 && proc->args[0].value >= -vm->nbr_players)
		{
			vm->p[ABS(proc->args[0].value) - 1].last_cycle_live = vm->cycle;
			vm->p[ABS(proc->args[0].value) - 1].total_live++;
			vm->nbr_live++;
			vm->last_live = proc->args[0].value;
			vm->last_live_cycle = vm->cycle;
			proc->live += 1;
			proc->last = 1;
		}
	}
	proc->pc = proc->pc_turfu / 2;
	l2(13, "INSTRUCTION", "instruction live", proc->id);
//	ft_printf("instruction %s\n", inst.name);
}
