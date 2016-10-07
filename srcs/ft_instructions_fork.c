#include "ft_corewar.h"

void	ft_instructions_fork(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	t_proc *new;
	int		i;

	(void)vm;
	new = 0;
	if (ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
		{
			proc_new(data(), new, proc->player, 0);
			new = vm->proc;
			i = new->id;
			ft_memcpy(new, proc, sizeof(proc));
			new->id = i;
			new->pc = (proc->pc + proc->args[0].value % IDX_MOD);


			// MIKA TEST
			// new->live = 1;
			new->last = 0;




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
