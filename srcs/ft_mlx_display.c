#include "ft_corewar.h"

void	reset_img(t_img *img)
{
	int		*ptr;

	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = 0xFF000000;
}

void	bloc_fadeout(t_img *i)
{
	static char	fade = 255;

	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		if (i->str[i->i + 3] != fade
		&& (i->str[i->i + 3] += BLOC_FADE) > fade)
			i->str[i->i + 3] = fade;
	}
		// {
		// 	i->str[i->i + 3] += BLOC_FADE;
		// 	if (i->str[i->i + 3] > 255)
		// 		i->str[i->i + 3] = 255;
		// }
		// else
		// 	ft_printf("good\n");
}

int		display(t_dmlx *m, t_dvm *v)
{
	l2(100, "DISPLAYING", "build and print screen..", v->cycle);
	itow(m->scene_img[2][0].img, 0, 0, "vm background");
	reset_img(&m->scene_img[2][11]);
	display_effect(m, v, effect_data(), -1);
	itow(m->scene_img[2][11].img, 0, 0, "effect layer");
	display_cycle(m, v);
	display_ctodie_bar(m, v, 0.0, 0);
	reset_img(&m->scene_img[2][10]);
	bloc_fadeout(&m->scene_img[2][26]);
	display_processus(m, v->proc, &m->scene_img[2][10], &m->scene_img[2][26]);
	display_processus_count(m, v);
	if (v->nbr_proc)
		display_bar_proc(m, v, &m->scene_img[2][10], 0);
	if (v->nbr_proc_dead)
		display_bar_proc_dead(m, v, &m->scene_img[2][10], 0);
	if (v->total_live)
		display_bar_proc_live(m, v, &m->scene_img[2][10], 0);
	itow(m->scene_img[2][10].img, 0, 0, "processus & bar layer");
	itow(m->scene_img[2][26].img, 0, 0, "processus bloc");
	display_arene(m, v, 0, 0);
	l2(-2, "display()", "printing cycle", v->cycle);
	return (1);
}
