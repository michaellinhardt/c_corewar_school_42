/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *proc)
{
	v->graphic += 0;
	while ( proc )
	{
		//attention pas oublier ls fonction POUR VERIF ERREUR ARGS 
		if (!proc->wait)
		{
			proc->pc_turfu = proc->pc * 2;
			ft_get_instruction(v->instructions, v, proc);
		}
		else if (proc->wait == 1)
		{
			proc->inst->f_instructions(v, *proc->inst, proc);
		}

		ft_printf("nbr live :%d\n", proc->live);
		proc->wait--;
		proc = proc->n;
	}
}
