/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *begin)
{
	t_proc *proc = begin;
	v->graphic += 0;
	
	while ( proc )
	{
		//ft_putnbr(v->cycle);
		/*
		if (proc->id != 0)
		{
			proc = proc->n;
			continue;
		}
		*/
		/*
		if (proc->wait-- == 1)
			proc->inst->f_instructions(v, *proc->inst, proc);
		if (proc->wait <= 0)
		{
			proc->pc_turfu = proc->pc * 2;
			if (!(ft_get_instruction(v->instructions, v, proc)))
			{
				proc->pc = (proc->pc + 1) % 4096 ;
				proc = proc->n;
				continue ;
			}
			proc->wait--;
		//	proc->wait++;
		}
		*/
		if (!proc->wait)
		{
			if (proc->inst)
			{
				proc->inst->f_instructions(v, *proc->inst, proc);
				proc->inst = 0;
				continue ;
			}
			else
			{
				proc->pc_turfu = proc->pc * 2;
				if (!(ft_get_instruction(v->instructions, v, proc)))
				{
					proc->pc = (proc->pc + 1) % 4096 ;
					proc = proc->n;
					proc->inst = 0;
					continue ;
				}
				else
					proc->wait--;
			}
			proc->ok = 0;
			//			proc->inst->f_instructions(v, *proc->inst, proc);
		}
		/*
		   else if (proc->wait == 2)
		   {
		   proc->inst->f_instructions(v, *proc->inst, proc);
		   }
		   else if (proc->wait == 1)
		   {
		   proc->inst->f_instructions(v, *proc->inst, proc);
		   }
		   */
		proc->wait--;
		proc = proc->n;
	}
}
