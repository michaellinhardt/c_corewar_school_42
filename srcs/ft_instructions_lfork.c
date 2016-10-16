#include "ft_corewar.h"

static t_proc *ft_create_lchild(t_proc *new, t_proc *father, int new_pc)
{
	ft_memcpy(new->reg, father->reg, REG_NUMBER * REG_SIZE);
	new->carry = father->carry;
	//new->pc = (father->pc + father->args[0].value);
	new->pc  = new_pc;
	new->pc = ft_convert_pc(new->pc);
	new->live = father->live;
	new->live_player = father->live_player;
	new->last_live = father->last_live;
	return (new);
}


void	ft_instructions_lfork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc *new;
	int 	opcode;
	int		new_pc;

	new = 0;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			opcode = ft_getchar(vm->arene + proc->pc * 2);
			new_pc = proc->args[0].value + proc->pc;;
			if (vm->options.operations)
			{
				ft_printf("P%5d | lfork %d (%d)\n", proc->id + 1, 
						proc->args[0].value, new_pc);
			}
				proc_new(data(), new, proc->player, 0);
				new = vm->proc;
				ft_create_lchild(new, proc, new_pc);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
	  	proc->pc %= MEM_SIZE;
	//proc->pc = (proc->pc_turfu) / 2;
	//proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
