/*
** GENERE L'AFFICHAGE DES PROCESSUS
*/
#include "ft_corewar.h"

void	display_processus(t_dmlx *m, t_proc *proc)
{
	int		x;
	int		y;

	m->loop += 0;

	while ( proc )
	{
		x = proc->i % VMPERLINE;
		y = proc->i / VMPERLINE;

		itow(m->scene_img[2][proc->player + 6].img
		, x * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX
		, y * VMSPACELINE + VMSTARTY + PROCDECALLAGEY
		, "processus displaying");

		proc = proc->n;
	}
}
