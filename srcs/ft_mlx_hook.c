/* FONCTION APPELLER PAR MINILIBX EN CAS D'APPUIS SOURIS/CLAVIER
 * - Le nom de la fonction est ainsi découpé: <touche><action>_hook
 * 		- touche = mouse ou key (clavier)
 * 		- action = [r]elease, [p]ress, [o]ver
 */
#include "ft_corewar.h"

int		mouseo_hook(int x, int y, t_data *d)
{
	/* ENREGISTRE LA POSITION DE LA SOURIS QUAND ELLE SE DEPLACE */
	d->mlx.input.mo_x = x;
	d->mlx.input.mo_y = y;
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	(key == 126) ? d->mlx.input.up = 0 : 0;
	if (key == 123)
		d->vm.cperloop -= (d->vm.cperloop - CPERLOOP_INC <= 0) ? 0 : CPERLOOP_INC;
	if (key == 124)
		d->vm.cperloop += (d->vm.cperloop + CPERLOOP_INC <= CPERLOOP_MAX) ? CPERLOOP_INC : 0;
	if (key == 125)
		d->vm.pause_inc = 1;
	if (key == 53)
		exit1(0, d, "by pressing echap");
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	(key == 126) ? d->mlx.input.up = 1 : 0;
	if (key == 49 && d->vm.pause == 1)
		d->vm.pause = 0;
	else if (key == 49 && d->vm.pause == 0)
		d->vm.pause = 1;
	return (d->mlx.loop += 0 * key);
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	(btn == 1) ? d->mlx.input.mleft = 1 : 0;
	(btn == 2) ? d->mlx.input.mright = 1 : 0;
	return (btn += 0 * d->mlx.loop * x * y);
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	(btn == 1) ? d->mlx.input.mleft = 0 : 0;
	(btn == 2) ? d->mlx.input.mright = 0 : 0;
	// getion des bouton + et - du bloc cycle
	if (d->mlx.input.mo_x >= BTNCTDPLUSX1 && d->mlx.input.mo_x <= BTNCTDPLUSX2
	&& d->mlx.input.mo_y >= BTNCTDPLUSY1 && d->mlx.input.mo_y <= BTNCTDPLUSY2)
		d->vm.cperloop -=
		(d->vm.cperloop - CPERLOOP_INC <= 0) ? 0 : CPERLOOP_INC;
	if (d->mlx.input.mo_x >= BTNCTDLESSX1 && d->mlx.input.mo_x <= BTNCTDLESSX2
	&& d->mlx.input.mo_y >= BTNCTDLESSY1 && d->mlx.input.mo_y <= BTNCTDLESSY2)
	d->vm.cperloop +=
		(d->vm.cperloop + CPERLOOP_INC <= CPERLOOP_MAX) ? CPERLOOP_INC : 0;
	/* ENREGISTRE LA POSITION DE LA SOURIS QUAND ON CLIC */
	d->mlx.input.mr_x = x;
	d->mlx.input.mr_y = y;
	return (btn += 0);
}
