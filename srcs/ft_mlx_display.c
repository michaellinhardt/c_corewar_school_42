/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

void	display_arene(t_dmlx *m, t_dvm *v)
{
	mlx_string_put(m->mlx, m->win, 100, 100, 0xbab9b9, "ceci est un test");
	v->graphic += 0;
}

void	display_cycle(t_dmlx *m, t_dvm *v)
{
	mlx_string_put(m->mlx, m->win, 1539, 197, 0xbab9b9, ft_itoastatic(v->cycle));
	v->graphic += 0;
}

void	display(t_dmlx *m, t_dvm *v)
{
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	display_cycle(m, v);
	display_arene(m, v);
	l2(-2, "display()", "printing cycle", v->cycle);
}
