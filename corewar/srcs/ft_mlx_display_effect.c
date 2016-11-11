/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_display_effect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:51 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:51 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GENERE LES EFFET
*/
#include "ft_corewar.h"

void	put_effect_img(t_img *l, int id, int x, int y)
{
	int			*ptre;
	int			*ptrl;
	t_effect	*e;

	e = effect_data();
	ptre = (int *)e[id].img->str;
	ptrl = (int *)l->str;
	l->i = (e[id].y * WIN_X + e[id].x) - 1;
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
	int		loopset;

	(void)v;
	loopset = 0;
	while ((++i || 1) && i < e[i].id_max
	&& l2(-2, "effect()", "(effect_id)", e[i].id_effect))
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
				put_effect_img(&m->scene_img[VM][11], i, -1, -1);
			else
				break ;
		}
	}
}
