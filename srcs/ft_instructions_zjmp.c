#include "ft_corewar.h"

static void	ft_log_zjmp_ok(t_dvm *vm, t_proc *proc)
{
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | zjmp %d OK\n", proc->id, proc->args[0].value);
		else if (proc->id < 100000)
			ft_printf("P%6d | zjmp %d OK\n", proc->id, proc->args[0].value);
		else
			ft_printf("P%7d | zjmp %d OK\n", proc->id, proc->args[0].value);
	}
}

static void	ft_log_zjmp_failed(t_dvm *vm, t_proc *proc)
{
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | zjmp %d FAILED\n", proc->id, proc->args[0].value);
		else if (proc->id < 100000)
			ft_printf("P%6d | zjmp %d FAILED\n", proc->id, proc->args[0].value);
		else
			ft_printf("P%7d | zjmp %d FAILED\n", proc->id, proc->args[0].value);
	}
}

void		ft_instructions_zjmp(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			log_inst(proc->player, proc->id, "ZJMP");
			if (proc->carry)
			{
				ft_log_zjmp_ok(vm, proc);
				proc->args[0].value %= IDX_MOD;
				proc->pc += (int)proc->args[0].value;
				proc->pc = ft_convert_pc(proc->pc);
				proc->pc %= MEM_SIZE;
				return ;
			}
			else
				ft_log_zjmp_failed(vm, proc);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
