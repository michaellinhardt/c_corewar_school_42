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
			proc->pc_turfu = 0;
			ft_get_instruction(v->instructions, v, proc);
		}
		else if (proc->wait == 1)
		{
			proc->inst->f_instructions(v, *proc->inst, proc);
		}
		ft_putnbr(v->nbr_live);
		ft_putchar('\n');
		proc->wait--;
		proc = proc->n;
	}
}
