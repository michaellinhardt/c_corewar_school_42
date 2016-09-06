/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

void	display_ctodie_bar(t_dmlx *m, t_dvm *v, double cycle)
{
	int		pixel;
	int		barsize;

	pixel = 0;
	barsize = 310;
	m->loop += v->graphic * 0;
	cycle = ((double)v->ctodiecount / (double)v->ctodie) * 100;
	itow(m->scene_img[2][3].img, 1543, 275, "bar_cycle_left");
	while ((((double)(pixel += 2) / barsize) * 100) < cycle)
		itow(m->scene_img[2][2].img, (1543 + pixel), 275, "bar_cycle_mid");
	itow(m->scene_img[2][1].img, (1543 + pixel), 275, "bar_cycle_right");
}

void	display_arene(t_dmlx *m, t_dvm *v)
{
	mlx_string_put(m->mlx, m->win, 100, 100, 0xbab9b9, "ceci est un test");
	v->graphic += 0;
}

void	display_cycle(t_dmlx *m, t_dvm *v)
{
	mlx_string_put(m->mlx, m->win, 1570, 195, 0x33cc33, ft_itoastatic(v->cycle));
	mlx_string_put(m->mlx, m->win, 1785, 195, 0x33cc33, ft_itoastatic(v->cperloop));
	mlx_string_put(m->mlx, m->win, 1570, 240, 0xff0000, ft_itoastatic(v->ctodiecount));
	mlx_string_put(m->mlx, m->win, 1780, 240, 0xff0000, ft_itoastatic(v->ctodie));
	v->graphic += 0;
}

void	display(t_dmlx *m, t_dvm *v)
{
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	display_cycle(m, v);
	display_ctodie_bar(m, v, 0.0);
	display_arene(m, v);
	l2(-2, "display()", "printing cycle", v->cycle);
}
