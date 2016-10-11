#include "ft_corewar.h"

static t_proc *ft_create_lchild(t_proc *new, t_proc *father)
{

	ft_memcpy(new->reg, father->reg, REG_NUMBER * REG_SIZE);
	new->carry = father->carry;
	new->pc = (father->pc + father->args[0].value) % 4096;
	new->live = father->live;
	//data()->vm.nbr_live += father->live;
	new->live_player = father->live_player;
	//data()->vm.live_player += new->live_player;
	return (new);
}


void	ft_instructions_lfork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc *new;
//	int opcode;

	(void)vm;
	(void)inst;
	(void)proc;
	new = 0;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		if (ft_get_args(proc))
		{
			if (vm->options.operations)
			{
				ft_printf("P%5d | lfork %d (%d)\n", proc->id + 1, 
						proc->args[0].value, proc->args[0].value + proc->pc);
			}
				proc_new(data(), new, proc->player, 0);
				new = vm->proc;
				ft_create_lchild(new, proc);
				//proc->pc += 11;
			//	proc->pc = proc->pc + 4;

		}
		/*
		   else
		   proc->pc = (father->pc + father->args[0].value) % 4096;
		   */
	}
	proc->pc = (proc->pc_turfu) / 2;
	/*
	ft_putnbr(proc->pc);
	ft_putchar('\n');
	*/
	//	ft_printf("instruction %s\n", inst.name);
}
