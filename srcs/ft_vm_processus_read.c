/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *proc)
{
	v->graphic += 0;
	while ( proc )
	{
		/*
		if (proc->id != 0)
		{
			proc = proc->n;
			continue;
		}
		*/
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
			proc->inst->f_instructions(v, *proc->inst, proc);
		}
		proc->wait--;

		proc = proc->n;
	}
}
