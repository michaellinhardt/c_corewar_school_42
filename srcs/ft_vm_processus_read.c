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
			//ft_get_instruction;
		}
		proc->wait--;
		proc = proc->n;
	}
}
