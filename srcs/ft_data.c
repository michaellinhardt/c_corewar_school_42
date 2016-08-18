/* FONCTIONS POUR INITIER ET RENVOYER LA STRUCTURE DATA
 */
#include "ft_corewar.h"

/* RENVOIE DATA à QUI LE DEMANDE (le bzero la première fois) */
t_data	*data(void)
{
	static t_data	d;
	static int		init = 0;

	if (!init && ++init)
		ft_bzero(&d, sizeof(t_data));
	return (&d);
}
