/* GESTION DE LA BOUCLE MLX, PILOTAGE DE TOUT LE PROGRAMME DEPUIS CETTE BOUCLE
 * loop_hook est appelé en boucle par la minilibx et c'est lui qui
 * en fonction de la scene actuel, pilote d'un coté l'affichage et de
 * l'autre coté il articule la vm
 */
#include "ft_corewar.h"

/* FONCTION QUI CHANGE L'ETAT DE m->loop
 * si m->loop = 0 alors aucun affichage n'est réalisé */
int		loop(char etat)
{
	t_dmlx *m;

	m = &(data()->mlx);
	if (m->loop && m->loopstop != 0)
		return (1);
	else
		m->loop = etat;
	(etat == 1) ? l(6, "LOOP STATUS", "-> 1") : l(6, "LOOP STATUS", "-> 0");
	return (1);
}

/* FONCITON APPELLER EN BOUCLE SI PAS DE MLX */
void	loop_vm(t_data *d)
{
	scene(d, &d->mlx, &d->mlx.input);
}

/* FONCITON APPELLER EN BOUCLE PAR MLX */
int		loop_hook(t_data *d)
{
	t_dmlx *m;

	m = &d->mlx;
	scene_img(d, &d->mlx);
	loop_vm(d);
	if (USLEEP_BOOL && m->loop == 0 && !usleep(USLEEP_TIME))
		return (0);
	if (m->loopstop != 0 && --m->loopstop < 1)
		loop(0);
	return (0);
}
