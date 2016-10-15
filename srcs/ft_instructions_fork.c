#include "ft_corewar.h"

static t_proc *ft_create_child(t_proc *new, t_proc *father)
{
	ft_memcpy(new->reg, father->reg, REG_NUMBER * REG_SIZE);
	new->carry = father->carry;
//	father->args[0].value  = ft_convert_pc(father->args[0].value % IDX_MOD);
	new->pc = (father->pc + father->args[0].value % IDX_MOD);
	new->pc = ft_convert_pc(new->pc);
	new->live = father->live;
	new->live_player = father->live_player;
	new->last_live = father->last_live;
//	ft_printf("proc-> pc %d\n", new->pc);

///	data()->vm.live_player += new->live_player;
	
	return (new);
}

void	ft_instructions_fork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc	*new;

	(void)vm;
	new = 0;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			if (vm->options.operations)
				ft_printf("P%5d | fork %d (%d)\n", proc->id + 1, proc->args[0].value, proc->args[0].value % IDX_MOD + proc->pc);
			proc_new(data(), new, proc->player, 0);
			new = vm->proc;
			ft_create_child(new, proc);
		}
	}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
	//proc->pc = proc->pc_turfu  / 2;
}
