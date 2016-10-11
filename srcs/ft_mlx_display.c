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
		itow(m->scene_img[2][4].img, BTNCTDPLUS1X, BTNCTDPLUS1Y
			, "btn_plus_over");
	if (m->input.mo_x >= BTNCTDLESSX1 && m->input.mo_x <= BTNCTDLESSX2
	&& m->input.mo_y >= BTNCTDLESSY1 && m->input.mo_y <= BTNCTDLESSY2)
		itow(m->scene_img[2][5].img, BTNCTDLESS1X, BTNCTDLESS1Y
			, "btn_less_over");
}

void	display_cycle(t_dmlx *m, t_dvm *v)
{
	mlx_string_put(m->mlx, m->win, TEXTCYCLEX, TEXTCYCLEY, 0x33cc33
		, ft_itoastatic(v->cycle));
	mlx_string_put(m->mlx, m->win, TEXTCPERLOOPX, TEXTCPERLOOPY, 0x33cc33
		, ft_itoastatic(v->cperloop));
	mlx_string_put(m->mlx, m->win, TEXTCTODIECOUNTX, TEXTCTODIECOUNTY, 0xff0000
		, ft_itoastatic(v->ctodiecount));
	mlx_string_put(m->mlx, m->win, TEXTCTODIEX, TEXTCTODIEY, 0xff0000
		, ft_itoastatic(v->ctodie));
}

int		display(t_dmlx *m, t_dvm *v)
{
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	display_cycle(m, v);
	display_ctodie_bar(m, v, 0.0, 0);
	display_processus(m, data()->vm.proc, &m->scene_img[2][10]);
	display_arene(m, v, 0, 0);

// DEBUG AFFICHE Nb PROC
mlx_string_put(m->mlx, m->win, TEXTCTODIEX - 130, TEXTCTODIEY + 100, 0xff0000
	, "PROC TOTAL: ");
	mlx_string_put(m->mlx, m->win, TEXTCTODIEX, TEXTCTODIEY + 100, 0xff0000
		, ft_itoastatic(v->nbr_proc));


	//l2(-2, "display()", "printing cycle", v->cycle);
	return (1);
}
