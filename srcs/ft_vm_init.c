/*
** INITIALISATION DE LA VM
*/
#include "ft_corewar.h"

void	vm_init(t_data *d, t_dvm *v, int i)
{
	ft_bzero(&d->vm, sizeof(t_dvm));
	// initialise a null la chaine de process mort (pour eviter de les remalloc)
	v->procdie = (t_proc *)NULL;


	// Debug pour forcer 4 joueurs ->
	v->p[0].playing = 1; v->p[1].playing = 1; v->p[2].playing = 1; v->p[3].playing = 1;

	// log terminal des valeur par default
	v->ctodie = (CYCLE_TO_DIE > -1) ? CYCLE_TO_DIE : 0;
	l2(11, "VM_INIT", "Cycle to die", CYCLE_TO_DIE);
	l2(11, "VM_INIT", "Cycle delta", CYCLE_DELTA);
	l2(11, "VM_INIT", "Nbr live", NBR_LIVE);
	l2(11, "VM_INIT", "Max Checks", MAX_CHECKS);
	l2(11, "VM_INIT", "Cycle per loop", CYCLE_PER_LOOP);

	// Créer le premier proc de chaque player
	while (--i > -1)
		if (v->p[i].playing && l2(11, "PLAYER", "is playing", i))
	 		proc_new(v, (t_proc *)NULL, i, i * (MEM_SIZE / 4));
		else if (!v->p[i].playing)
			l2(11, "PLAYER", "is not plaing", i);
	// Change la scene actuel pour afficher la vm
	d->mlx.scene = VM;
	exit1(0, d, "test");
}
