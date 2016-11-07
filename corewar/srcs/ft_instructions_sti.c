#include "ft_corewar.h"

static void	ft_log_sti(t_dvm *vm, t_proc *proc, int registre)
{
	int add;
	int address;

	add = (proc->args[1].value + proc->args[2].value);
	address = add % IDX_MOD + proc->pc % MEM_SIZE;
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | sti r%d %d %d\n", proc->id, registre,
					proc->args[1].value, proc->args[2].value);
		else if (proc->id < 100000)
			ft_printf("P%6d | sti r%d %d %d\n", proc->id,
					registre, proc->args[1].value, proc->args[2].value);
		else
			ft_printf("P%7d | sti r%d %d %d\n", proc->id, registre,
					proc->args[1].value, proc->args[2].value);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				proc->args[1].value, proc->args[2].value, add, address);
	}
}

void		ft_instructions_sti(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int add;
	int address;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[0].value;
		if (ft_get_args(proc))
		{
			log_inst(proc->player, proc->id, "STI");
			if (proc->args[1].type == IND_CODE)
				proc->args[1].type %= IDX_MOD;
			add = (proc->args[1].value + proc->args[2].value);
			address = add % IDX_MOD + proc->pc % MEM_SIZE;
			ft_log_sti(vm, proc, registre);
			address = ft_convert_pc(address);
			address *= 2;
			ft_put_registre(vm->arene, proc->args[0].value,
					address % SIZE_CHAR_ARENE);
			ft_put_color_size(vm->color, vm->code_color[ABS(proc->player)],
					address / 2, 4);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
