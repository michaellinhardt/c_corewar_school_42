/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

int		display(t_dmlx *m, t_dvm *v)
{
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	//display_effect(m, v, effect_data(), -1);
	//display_cycle(m, v);
	//display_ctodie_bar(m, v, 0.0, 0);
	//display_processus(m, data()->vm.proc, &m->scene_img[2][10]);
	//display_arene(m, v, 0, 0);

	l2(100, "display()", "printing cycle", v->cycle);
	return (1);

	// DEBUG AFFICHE Nb PROC
	// mlx_string_put(m->mlx, m->win, TEXTCTODIEX - 130, TEXTCTODIEY + 100, 0xff0000
	// 	, "PROC TOTAL: ");
	// 	mlx_string_put(m->mlx, m->win, TEXTCTODIEX, TEXTCTODIEY + 100, 0xff0000
	// 		, ft_itoastatic(v->nbr_proc));
}
