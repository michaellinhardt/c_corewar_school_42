#include "ft_corewar.h"

void	vm_init_log(void)
{
	l2(11, "VM_INIT", "Cycle to die", CYCLE_TO_DIE);
	l2(11, "VM_INIT", "Cycle delta", CYCLE_DELTA);
	l2(11, "VM_INIT", "Nbr live", NBR_LIVE);
	l2(11, "VM_INIT", "Max Checks", MAX_CHECKS);
	l2(11, "VM_INIT", "Cycle per loop", CYCLE_PER_LOOP);
}

void	vm_init_proc(t_data *d, t_dvm *v, int player)
{
	while (++player < MAX_PLAYERS)
		if (v->p[player].playing && l2(11, "PLAYER", "joue", player))
			proc_new(d, (t_proc *)NULL, -(player + 1)
			, (player * MEM_SIZE) / v->nbr_players);
		else if (!v->p[player].playing)
			l2(11, "PLAYER", "ne joue pas", player);
}

void	vm_init(t_data *d, t_dvm *v)
{
	ft_memset(&v->arene, '0', SIZE_CHAR_ARENE);
	ft_fill_arene(v);
	v->ctodie = CYCLE_TO_DIE;
	v->cperloop = CYCLE_PER_LOOP;
	v->max_checks = 0;
	vm_init_log();
	vm_init_proc(d, v, -1);
	d->mlx.scene = VM;
}
