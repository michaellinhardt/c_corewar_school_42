/*
** INITIALISE LES EFFET
*/
#include "ft_corewar.h"

/* RENVOIE DATA à QUI LE DEMANDE (le bzero la première fois) */
t_effect	*effect_data(void)
{
	static t_effect	e[EFFECTS_MAX_SLOT];

	return (e);
}

void	effect_init(t_dmlx *m, t_dvm *v, t_effect *e, int i)
{
	e = effect_data();
	ft_bzero(e, sizeof(e));
	while (++i < 1)
		e[i].id_effect = i;
	e[0].img = &m->scene_img[2][CPERLOOP_NUMBER];
	l2(101, "EFFECT_INIT", "(scene_img id) CPERLOOP_NUMBER", CPERLOOP_NUMBER);
	(void)v;
}
