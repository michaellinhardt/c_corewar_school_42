/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

void	reset_img(t_img *img)
{
	int		*ptr;

	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = 0xFF000000;
}

int		display(t_dmlx *m, t_dvm *v)
{
	itow(m->scene_img[2][0].img, 0, 0, "vm background");

	reset_img(&m->scene_img[2][11]);
	display_effect(m, v, effect_data(), -1);
	itow(m->scene_img[2][11].img, 0, 0, "effect layer");

	display_cycle(m, v);
	display_ctodie_bar(m, v, 0.0, 0);

	reset_img(&m->scene_img[2][10]);
	display_processus(m, v->proc, &m->scene_img[2][10]);
	display_processus_count(m, v);
	itow(m->scene_img[2][10].img, 0, 0, "processus layer");

	display_arene(m, v, 0, 0);

	l2(100, "display()", "printing cycle", v->cycle);
	return (1);

	// DEBUG AFFICHE Nb PROC
	// mlx_string_put(m->mlx, m->win, TEXTCTODIEX - 130, TEXTCTODIEY + 100, 0xff0000
	// 	, "PROC TOTAL: ");
	// 	mlx_string_put(m->mlx, m->win, TEXTCTODIEX, TEXTCTODIEY + 100, 0xff0000
	// 		, ft_itoastatic(v->nbr_proc));
}
