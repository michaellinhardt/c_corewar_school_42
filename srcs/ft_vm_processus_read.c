/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *begin)
{
	int pc;
	t_proc *proc = begin;
	v->graphic += 0;

	if (v->options.cycles)
		ft_printf("It is now cycle %d\n", v->cycle);
	while ( proc )
	{
		if (!proc->wait)
		{
				proc->pc_turfu = proc->pc * 2;
				if (!(ft_get_instruction(v->instructions, v, proc)))
				{
					proc->pc = (proc->pc + 1) % 4096 ;
					proc = proc->n;
					continue ;
				}
		}
		else if (proc->wait == 1)
		{
			pc = proc->pc;
			proc->inst->f_instructions(v, *proc->inst, proc);
			ft_printf("decalage %d\n", proc->pc - pc);

		}
		proc->wait--;
		proc = proc->n;
	}
}
