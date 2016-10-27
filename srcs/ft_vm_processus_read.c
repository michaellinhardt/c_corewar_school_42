#include "ft_corewar.h"

static void		ft_affadv(const t_dvm *vm, t_proc *proc, int pc)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ((proc->pc - pc));
	j = ft_convert_pc(j);
	pc = ft_convert_pc(pc);
	pc = pc >= MEM_SIZE ? pc %= MEM_SIZE : pc;
	k = pc + j;
	if (k > MEM_SIZE)
		k %= MEM_SIZE;
	if (pc)
		ft_printf("ADV %d (%#06x -> %#06x) ", j, pc, k);
	else
		ft_printf("ADV %d (0x0000 -> %#06x) ", j, k);
	j *= 2;
	pc *= 2;
	while (i < j)
	{
		ft_putchar(ft_tolower(*(vm->arene + ((pc + i++) % SIZE_CHAR_ARENE))));
		ft_putchar(ft_tolower(*(vm->arene + ((pc + i++) % SIZE_CHAR_ARENE))));
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

static void		ft_display_cycle(const t_dvm *v)
{
	if (v->options.cycles)
	{
		ft_putstr("It is now cycle ");
		ft_putnbr(v->cycle);
		ft_putchar('\n');
	}
}

static void		ft_lunch_instruction(t_dvm *v, t_proc *proc)
{
	int		pc;

	pc = 0;
	pc = proc->pc;
	proc->inst->f_instructions(v, *proc->inst, proc);
	if (v->options.movements && (proc->inst->id != 9 || proc->carry == 0))
		ft_affadv(v, proc, pc);
	proc->wait = 0;
}

void			processus_read(t_dvm *v, t_proc *begin)
{
	t_proc	*proc;

	proc = begin;
	ft_display_cycle(v);
	while (proc)
	{
		if (proc->wait <= 0)
		{
			if (!(ft_get_instruction(v->instructions, v, proc)))
			{
				proc->pc = (proc->pc + 1) % MEM_SIZE;
				proc->mlx_status = -1;
				proc = proc->n;
				continue ;
			}
		}
		else if (proc->wait == 1)
			ft_lunch_instruction(v, proc);
		proc->wait--;
		proc = proc->n;
	}
}
