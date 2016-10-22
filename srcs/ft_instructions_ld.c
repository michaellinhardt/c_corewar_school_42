#include "ft_corewar.h"

static void		ft_log_ld(t_dvm *vm, t_proc *proc, int registre)
{
	log_inst(proc->player, proc->id, "LD");
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | ld %d r%d\n", proc->id,
					proc->args[0].value, registre);
		else if (proc->id < 100000)
			ft_printf("P%6d | ld %d r%d\n", proc->id,
					proc->args[0].value, registre);
		else
			ft_printf("P%7d | ld %d r%d\n", proc->id,
					proc->args[0].value, registre);
	}
}

void			ft_instructions_ld(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[1].value;
		if (ft_get_args(proc))
		{
			if (proc->args[0].type == IND_CODE)
				proc->args[0].value = ft_get_indirect(proc->args[0].value,
						vm, proc);
			ft_log_ld(vm, proc, registre);
			if ((*(proc->ireg + --registre) = proc->args[0].value))
				proc->carry = 0;
			else
				proc->carry = 1;
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
