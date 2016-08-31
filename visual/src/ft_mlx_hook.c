/* FONCTION APPELLER PAR MINILIBX EN CAS D'APPUIS SOURIS/CLAVIER
 * - Le nom de la fonction est ainsi découpé: <touche><action>_hook
 * 		- touche = mouse ou key (clavier)
 * 		- action = [r]elease, [p]ress, [o]ver
 */
#include "ft_corewar.h"

int		mouseo_hook(int x, int y, t_data *d)
{
	static t_dmlx	*m;

	m = &d->mlx;
	/* ENREGISTRE LA POSITION DE LA SOURIS QUAND ELLE SE DEPLACE */
	m->input.mo_x = x;
	m->input.mo_y = y;
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	if (key == 53)
		exit1(0, d, "by pressing echap");
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	static t_dmlx	*m;

	m = &d->mlx;
	return (m->loop += 0 * key);
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	static t_dmlx	*m;

	m = &d->mlx;
	return (btn += 0 * m->loop * x * y);
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	static t_dmlx	*m;

	m = &d->mlx;
	/* ENREGISTRE LA POSITION DE LA SOURIS QUAND ON CLIC */
	m->input.mr_x = x;
	m->input.mr_y = y;
	return (btn += 0);
}
