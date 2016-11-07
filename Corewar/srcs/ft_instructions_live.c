#include "ft_corewar.h"

static void	ft_log_live(t_dvm *vm, t_proc *proc)
{
	log_inst(proc->player, proc->id, "LIVE");
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | live %d\n", proc->id, proc->args[0].value);
		else if (proc->id < 100000)
			ft_printf("P%6d | live %d\n", proc->id, proc->args[0].value);
		else
			ft_printf("P%7d | live %d\n", proc->id, proc->args[0].value);
	}
}

static void	ft_that_what_she_said(t_dvm *vm, t_proc *proc)
{
	if (vm->options.lives)
	{
		ft_printf("Player %d (%s) is said to be alive\n",
				ABS(proc->args[0].value),
				vm->p[(ABS(proc->args[0].value)) - 1].header.prog_name);
	}
}

static void	ft_execute_studio(t_dvm *vm, t_proc *proc)
{
	vm->p[(ABS(proc->args[0].value)) - 1].last_cycle_live = vm->cycle;
	vm->p[(ABS(proc->args[0].value)) - 1].total_live++;
	vm->p[(ABS(proc->args[0].value)) - 1].total_live_current++;
	vm->nbr_live_current++;
	proc->live_player++;
	vm->last_live = proc->args[0].value;
	vm->last_live_cycle = vm->cycle;
	vm->live_player++;
	vm->total_live++;
}

void		ft_instructions_live(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	if (vm->ctodie > 0)
	{
		vm->nbr_live++;
		proc->live += 1;
	}
	proc->last_live = vm->cycle;
	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		ft_log_live(vm, proc);
		if (proc->args[0].value <= -1
			&& proc->args[0].value >= -vm->nbr_players)
		{
			ft_that_what_she_said(vm, proc);
			if (vm->ctodie > 0)
				ft_execute_studio(vm, proc);
			ft_put_color_size(vm->color,
					vm->code_color[(ABS(proc->player)) + 4], proc->pc + 1, 4);
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
