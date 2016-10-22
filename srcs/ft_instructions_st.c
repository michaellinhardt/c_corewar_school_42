#include "ft_corewar.h"

static void	ft_log_st_reg(t_dvm *vm, t_proc *proc, int registre1, int registre)
{
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | st r%d r%d\n", proc->id, registre1, registre);
		else if (proc->id < 100000)
			ft_printf("P%6d | st r%d r%d\n", proc->id, registre1, registre);
		else
			ft_printf("P%7d | st r%d r%d\n", proc->id, registre1, registre);
	}
}

static void	ft_log_st(t_dvm *vm, t_proc *proc, int registre1, int registre)
{
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | st r%d %d\n", proc->id, registre1, registre);
		else
			ft_printf("P%6d | st r%d %d\n", proc->id, registre1, registre);
	}
}

static void	ft_init_st(int *tab, t_proc *proc)
{
	tab[0] = proc->args[1].value;
	tab[1] = proc->args[0].value;
	proc->args[1].value = (proc->args[1].value) % IDX_MOD;
	tab[2] = ft_convert_pc(proc->args[1].value);
}

void		ft_instructions_st(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int	tab[3];

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		ft_init_st(tab, proc);
		if (ft_get_args(proc))
		{
			log_inst(proc->player, proc->id, "ST");
			if (proc->args[1].type == REG_CODE && tab[0] > 0 && tab[0] <= 16)
			{
				ft_log_st_reg(vm, proc, tab[1], tab[0]);
			}
			else
			{
				ft_log_st(vm, proc, tab[1], tab[0]);
				ft_put_registre(vm->arene, (unsigned int)proc->args[0].value,
						((proc->pc + tab[2]) * 2) % SIZE_CHAR_ARENE);
				ft_put_color_size(vm->color, vm->code_color[ABS(proc->player)],
						proc->pc + tab[2], 4);
			}
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
