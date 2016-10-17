#include "ft_corewar.h"

static void	ft_log_ldi(t_dvm *vm, t_proc *proc, int *tab)
{
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | ldi %d %d r%d\n", proc->id, proc->args[0].value,
					proc->args[1].value, tab[0]);
		else if (proc->id < 100000)
			ft_printf("P%6d | ldi %d %d r%d\n", proc->id, proc->args[0].value,
					proc->args[1].value, tab[0]);
		else
			ft_printf("P%7d | ldi %d %d r%d\n", proc->id, proc->args[0].value,
					proc->args[1].value, tab[0]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				proc->args[0].value, proc->args[1].value, tab[1], tab[2]);
	}
}

void		ft_instructions_ldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int tab[3];

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		tab[0] = proc->args[2].value;
		if (ft_get_args(proc))
		{
			tab[1] = (proc->args[0].value + proc->args[1].value);
			tab[2] = tab[1] % 512;
			tab[2] += proc->pc % MEM_SIZE;
			ft_log_ldi(vm, proc, tab);
			tab[1] %= IDX_MOD;
			tab[1] += proc->pc;
			*(proc->ireg + --tab[0]) = ft_get_indirect(tab[1], vm, proc);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
