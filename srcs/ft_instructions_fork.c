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
//	t_proc	*next;
//	t_proc	*prev;
//	int		*ireg;
//	int		i;

	(void)vm;
	new = 0;
	if (ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
		{
			proc_new(data(), new, proc->player, 0);
			new = vm->proc;
			ft_create_child(new, proc);
			new->pc_turfu = new->pc * 2;
			ft_get_instruction(vm->instructions, vm, new);

			/*
			next = new->n;
			prev = new->p;
			ireg = (int *)new->reg;
			i = new->id;
			ft_memcpy(new, proc, sizeof(t_proc));
			new->n = next;
			new->p = prev;
			new->ireg = ireg;
			ft_printf("[fork] proc.r2 = %d <-> new.r2 = %d\n", proc->ireg[1], new->ireg[1]);
			// ft_printf("[fork] proc.last = %d <-> new.last = %d\n", proc->last, new->last);
			// ft_printf("[fork] proc.player = %d <-> new.player = %d\n", proc->player, new->player);

			new->id = i;
			new->pc = (proc->pc + proc->args[0].value % IDX_MOD);
			*/


			// MIKA TEST
			// new->live = 0;
			//new->last = 0;





			/*
			if (!(ft_get_instruction(vm->instructions, vm, new)))
			{
				new->pc = (new->pc + 1) % 4096 ;
			}
			*/

		//	proc->carry = 1;
		//	new->carry = 0;
		}
	}
	l2(13, "INSTRUCTION", "instruction fork", proc->id);
	proc->pc = proc->pc_turfu / 2;
	//ft_printf("instruction %s\n", inst.name);
}
