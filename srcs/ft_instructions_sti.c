#include "ft_corewar.h"

void	ft_instructions_sti(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int add;
	int address;
	(void)vm;
	(void)inst;
	(void)proc;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[0].value;
		if (ft_get_args(proc))
		{
			if (proc->args[1].type == IND_CODE)
				proc->args[1].type %= IDX_MOD;
			add = (proc->args[1].value + proc->args[2].value);
			address = add % IDX_MOD + proc->pc;
			if (vm->options.operations)
			{
				ft_printf("P%5d | sti r%d %d %d\n", proc->id + 1, registre, proc->args[1].value, proc->args[2].value);
				ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", proc->args[1].value, proc->args[2].value, add, (address));
			}
			address = ft_convert_pc(address);
			address *= 2;
			ft_put_registre(vm->arene, proc->args[0].value , address % SIZE_CHAR_ARENE);
			ft_put_color_size(vm->color, ARENE_CODE_COLOR_P2,
					address / 2, 4);
		}
	}
	//proc->pc = proc->pc_turfu / 2;
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
	  	proc->pc %= MEM_SIZE;
	//proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
}
