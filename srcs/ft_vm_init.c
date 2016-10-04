/*
** INITIALISATION DE LA VM
*/
#include "ft_corewar.h"

void	vm_init_log(void)
{
	// log terminal des valeur par default
	l2(11, "VM_INIT", "Cycle to die", CYCLE_TO_DIE);
	l2(11, "VM_INIT", "Cycle delta", CYCLE_DELTA);
	l2(11, "VM_INIT", "Nbr live", NBR_LIVE);
	l2(11, "VM_INIT", "Max Checks", MAX_CHECKS);
	l2(11, "VM_INIT", "Cycle per loop", CYCLE_PER_LOOP);
}

void	vm_init_proc(t_data *d, t_dvm *v, int player)
{

	// Créer le premier proc de chaque player
	// i * (MEM_SIZE / 4) représente le début du premier processeur de ce joueur dans l'arene
	// i est sont numéro (0-3) et MEM_SIZE / 4 la taille max par champion
	// nb: c'est peut être pas le bon calcule, à vérifier avant merge
	while (++player < MAX_PLAYERS)
		if (v->p[player].playing && l2(11, "PLAYER", "joue", player))
			proc_new(d, (t_proc *)NULL, player
			, (player * MEM_SIZE) / v->nbr_players);
		else if (!v->p[player].playing)
			l2(11, "PLAYER", "ne joue pas", player);
	// Change la scene actuel pour afficher la vm

}

void	vm_init(t_data *d, t_dvm *v)
{
	/*
	d->proc = (t_proc *)NULL;
	d->procdie = (t_proc *)NULL;
	*/

	ft_memset(&v->arene, '0', SIZE_CHAR_ARENE);
	ft_fill_arene(v);

	// initialise les variable et les log
	v->ctodie = CYCLE_TO_DIE;
	v->cperloop = CYCLE_PER_LOOP;
	vm_init_log();

	vm_init_proc(d, v, -1);

	d->mlx.scene = VM;

/*
	// debug..force le live sur tout les joueur
	d->proc->live = 1; // 3
	(d->proc->n)->live = 1; // 2
	((d->proc->n)->n)->live = 1; // 1
	(((d->proc->n)->n)->n)->live = 1; // 0
	// v->ctodie = 300;
*/
}
