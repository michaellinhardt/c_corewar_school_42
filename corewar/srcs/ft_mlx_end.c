/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:53 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:53 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	vm_end_shadow(t_img *i)
{
	static int	fade = 255;

	if (fade > 150)
	{
		fade -= VM_FADEOUT_SPEED;
		i->i = -4;
		while ((i->i += 4) < (i->sl * WIN_Y))
			i->str[i->i + 3] = fade;
	}
	itow(i->img, 0, 0, "fade in");
}

void	vm_end(t_dmlx *m, t_dvm *v, t_img *i)
{
	char	*player;

	ft_printf("%!%d. %s", &player, (ABS(v->last_live))
	, v->p[(ABS(v->last_live)) - 1].header.prog_name);
	display(m, v);
	vm_end_shadow(i);
	itow(m->scene_img[VM][34].img, WINNERIMGX, WINNERIMGY, "winner");
	mlx_string_put(m->mlx, m->win, WINNERTXTX - ((ft_strlen(player) / 2)
	* TXTDECALLAGEX), WINNERTXTY, WINNERCOLOR, player);
	ft_strdel(&player);
}
