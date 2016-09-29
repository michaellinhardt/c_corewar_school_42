/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *proc)
{
	v->graphic += 0;
	while ( proc )
	{
		instructions(v, proc);
		proc = proc->n;
	}
}
