/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *proc)
{
	v->graphic += 0;
	while ( proc )
	{
		//instructions(v, proc);
		//
		//
		/*
		Si on as pas d'instructions -> decoder l'instruction
		decode_instruction
		init le pointeur vers la bonne fonction avec le wait
		attendre

		execute la fonction qui coresspond au code; -> elle modifie le PC
		*/


		proc = proc->n;
	}
}
