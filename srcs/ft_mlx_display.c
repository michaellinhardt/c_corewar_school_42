/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

void	display_ctodie_bar(t_dmlx *m, t_dvm *v, double cycle, int pixel)
{
	m->loop += v->graphic * 0;
	cycle = ((double)v->ctodiecount / (double)v->ctodie) * 100;
	itow(m->scene_img[2][3].img
		, BARCTDLEFTX, BARCTDLEFTY, "bar_cycle_left");
	while ((((double)(pixel += 2) / BARCTDSIZE) * 100) < cycle)
		itow(m->scene_img[2][2].img, (BARCTDLEFTX + pixel)
		, BARCTDLEFTY, "bar_cycle_mid");
	itow(m->scene_img[2][1].img, (BARCTDLEFTX + pixel)
	, BARCTDLEFTY, "bar_cycle_right");
	if (m->input.mo_x >= BTNCTDPLUSX1 && m->input.mo_x <= BTNCTDPLUSX2
	&& m->input.mo_y >= BTNCTDPLUSY1 && m->input.mo_y <= BTNCTDPLUSY2)
		if (itow(m->scene_img[2][4].img, BTNCTDPLUS1X, BTNCTDPLUS1Y, "btn_plus_over")
		&& (m->input.mleft == 1))
			itow(m->scene_img[2][5].img, BTNCTDPLUS1X, BTNCTDPLUS1Y, "btn_plus_push");
	if (m->input.mo_x >= BTNCTDLESSX1 && m->input.mo_x <= BTNCTDLESSX2
	&& m->input.mo_y >= BTNCTDLESSY1 && m->input.mo_y <= BTNCTDLESSY2)
		if (itow(m->scene_img[2][6].img, BTNCTDLESS1X, BTNCTDLESS1Y, "btn_less_over")
		&& (m->input.mleft == 1))
			itow(m->scene_img[2][7].img, BTNCTDLESS1X, BTNCTDLESS1Y, "btn_less_push");

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
}

void	display(t_dmlx *m, t_dvm *v)
{
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	display_cycle(m, v);
	display_ctodie_bar(m, v, 0.0, 0);
	display_arene(m, v);
	l2(-2, "display()", "printing cycle", v->cycle);
}
