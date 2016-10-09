#include "ft_corewar.h"

static t_proc *ft_create_child(t_proc *new, t_proc *father)
{
	ft_memcpy(new->reg, father->reg, REG_NUMBER * REG_SIZE);
	new->carry = father->carry;
	new->pc = (father->pc + father->args[0].value % IDX_MOD);
	new->live = father->live;
	return (new);
}

void	ft_instructions_fork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc	*new;

	(void)vm;
	new = 0;
	l2(13, "INSTRUCTION", "instruction fork", proc->id);
//	ft_putendl("fourchette");
		if (ft_check_value_args(proc->args, &inst))
		{
			if (ft_get_args(proc))
			{
			proc_new(data(), new, proc->player, 0);
			new = vm->proc;
			ft_create_child(new, proc);
			}
		}
		proc->pc = proc->pc_turfu / 2;
	l2(13, "INSTRUCTION", "instruction fork", proc->id);
	//ft_printf("instruction %s\n", inst.name);
}
