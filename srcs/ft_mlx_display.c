/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

void	display(t_dmlx *m, t_dvm *v)
{
	v->cperprintcount = 0;
	m->loop += 0;
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	l2(-2, "display()", "printing cycle", v->cycle);
}
