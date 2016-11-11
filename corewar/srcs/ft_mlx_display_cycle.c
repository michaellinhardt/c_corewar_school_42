/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_display_cycle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:51 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:51 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GENERE L'AFFICHAGE
*/
#include "ft_corewar.h"

void	display_ctodie_bar(t_dmlx *m, t_dvm *v, double cycle, int pixel)
{
	cycle = ((double)v->ctodiecount / (double)v->ctodie) * 100;
	itow(m->scene_img[VM][3].img
		, BARCTDLEFTX, BARCTDLEFTY, "bar_cycle_left");
	while ((((double)(pixel += 2) / BARCTDSIZE) * 100) < cycle)
		itow(m->scene_img[VM][2].img, (BARCTDLEFTX + pixel)
		, BARCTDLEFTY, "bar_cycle_mid");
	itow(m->scene_img[VM][1].img, (BARCTDLEFTX + pixel)
	, BARCTDLEFTY, "bar_cycle_right");
	if (m->input.mo_x >= BTNCTDPLUSX1 && m->input.mo_x <= BTNCTDPLUSX2
	&& m->input.mo_y >= BTNCTDPLUSY1 && m->input.mo_y <= BTNCTDPLUSY2)
		itow(m->scene_img[VM][4].img, BTNCTDPLUS1X, BTNCTDPLUS1Y
			, "btn_less_over");
	if (m->input.mo_x >= BTNCTDLESSX1 && m->input.mo_x <= BTNCTDLESSX2
	&& m->input.mo_y >= BTNCTDLESSY1 && m->input.mo_y <= BTNCTDLESSY2)
		itow(m->scene_img[VM][5].img, BTNCTDLESS1X, BTNCTDLESS1Y
			, "btn_plus_over");
}

void	display_cycle(t_dmlx *m, t_dvm *v)
{
	char	txt[500];

	mlx_string_put(m->mlx, m->win, TEXTCYCLEX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->cycle))) / 2) * TXTDECALLAGEX)
	, TEXTCYCLEY, TXTCOLACTUAL, txt);
	mlx_string_put(m->mlx, m->win, TEXTCPERLOOPX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->cperloop))) / 2) * TXTDECALLAGEX)
	, TEXTCPERLOOPY, TXTCOLACTUAL, txt);
	mlx_string_put(m->mlx, m->win, TEXTCTODIECOUNTX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->ctodiecount))) / 2) * TXTDECALLAGEX)
	, TEXTCTODIECOUNTY, TXTCOLACTUAL, txt);
	mlx_string_put(m->mlx, m->win, TEXTCTODIEX, TEXTCTODIEY, TXTCOLCTODIE
		, ft_itoastatic(v->ctodie));
}
