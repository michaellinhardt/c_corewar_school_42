#include "ft_corewar.h"

static t_proc *ft_create_lchild(t_proc *new, t_proc *father)
{
	ft_memcpy(new->reg, father->reg, REG_NUMBER * REG_SIZE);
	new->carry = father->carry;
	new->pc = (father->pc + father->args[0].value);
	new->live = father->live;
	return (new);
}


void	ft_instructions_lfork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc *new;

	(void)vm;
	(void)inst;
	(void)proc;
	new = 0;


	if (proc->wait == inst.cycles)
	{
		if (ft_check_value_args(proc->args, &inst))
		{
			if (ft_get_args(proc))
				proc->ok = 1;
		}
	}
	else
	{
		if (proc->ok)
		{
			proc_new(data(), new, proc->player, 0);
			new = vm->proc;
			ft_create_lchild(new, proc);
		}
		proc->pc = proc->pc_turfu / 2;
	}
	//	ft_printf("instruction %s\n", inst.name);
}
