/*
** GENERE LES EFFET
*/
#include "ft_corewar.h"

void	reset_img_effect(t_img *img)
{
	int		*ptr;

	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = 0xFF000000;
}

void	put_effect_img(t_img *l, int id, int x, int y)
{
	int			*ptre;
	int			*ptrl;
	t_effect	*e;

	e = effect_data();
	ptre = (int *)e[id].img->str;
	ptrl = (int *)l->str;
	l->i = (e[id].y * WIN_X + e[id].x) - 1;
	// ft_printf("image position: %d,%d\n(e[id].y * WIN_X + e[id].x) - 1 = %d\n", e[id].x, e[id].y, l->i);
	// exit (0);
	while (++y < e[id].size_y)
	{
		x = -1;
		while (++x < e[id].size_x)
		{
			ptrl[++(l->i)] = ptre[y * e[id].size_x + x];
			l->str[l->i * 4 + 3] = e[id].fade;
		}
		l->i = l->i - x + WIN_X;
	}
	e[id].fade += e[id].inc_value;
}

void	display_effect(t_dmlx *m, t_dvm *v, t_effect *e, int i)
{
	(void)m;
	(void)v;
	int		loopset;

	loopset = 0;
	reset_img_effect(&m->scene_img[2][11]);
	while ((++i || 1) && i < e[i].id_max
	&& l2(101, "effect()", "(effect_id)", e[i].id_effect))
	{
		if ((e[i].start_cycle && e[i].looptodie == 0 && !(e[i].start_cycle = 0)
		&& l2(101, "EFFECT_START", "(id_effect) start", e[i].id_effect)
		&& (e[i].looptodie = e[i].looptodie_count)
		&& l2(101, "EFFECT_TODIE", "(looptodie) count start", e[i].looptodie))
		|| ((e[i].looptodie > 0 && --(e[i].looptodie)
		&& (loopset += e[i].looptodie)
		&& l2(101, "EFFECT_PRINT", "(looptodie) print to layer"
		, e[i].looptodie))))
		{
			if (e[i].id_effect == 0 && l2(-2, "EFFECT_PRINT"
			, "(looptodie) still alive", e[i].looptodie))
				put_effect_img(&m->scene_img[2][11], i, -1, -1);
			else
				break ;
		}
	}
	if (m->loop && loopset == 0)
		loop(0);
	itow(m->scene_img[2][11].img, 0, 0, "effect layer");
}
