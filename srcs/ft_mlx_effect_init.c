/*
** INITIALISE LES EFFET
*/
#include "ft_corewar.h"

/* RENVOIE DATA à QUI LE DEMANDE (le bzero la première fois) */
t_effect	*effect_data(void)
{
	static t_effect	e[EFFECTS_MAX_SLOT];
	static int		init = 0;

	if (!init && ++init)
		ft_bzero(&e, sizeof(e));
	return (e);
}

void	effect_init(t_dmlx *m, t_dvm *v, t_effect *e)
{
	e = effect_data();
	(void)m;
	(void)v;
	(void)e;
}
