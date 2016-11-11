/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_display_processus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:52 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:52 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	put_proc_bloc(t_img *img, t_img *bloc, int x, int y)
{
	int			*pbloc;
	int			*pimg;

	pbloc = (int *)bloc->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < BLOCY)
	{
		x = -1;
		while (++x < BLOCX)
			pimg[++(img->i)] = pbloc[y * BLOCX + x];
		img->i = img->i - x + WIN_X;
	}
}

int		cxy(t_mlx_proc *d, int pc)
{
	d->x = (pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
	d->y = (pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
	return (1);
}

void	display_processus(t_dmlx *m, t_proc *proc, t_img *bloc)
{
	t_mlx_proc		d;

	if (ft_bzero(m->already, sizeof(m->already)) && m->scene == END)
		return ;
	while (proc && cxy(&d, proc->pc))
	{
		if (m->already[(proc->pc)] && ((proc = proc->n) || 1))
			continue ;
		d.opc = (proc->inst) ? proc->inst->id : ft_getchar(
		data()->vm.arene + (proc->pc * 2) % SIZE_CHAR_ARENE);
		put_proc_bloc(bloc, &m->scene_img[VM][-proc->player + 28], d.x, d.y);
		d.pc = 0;
		if (d.opc > 0 && d.opc < 17 && ((d.e.pc = proc->pc % MEM_SIZE) || 1))
		{
			if (ft_get_instruction(data()->vm.instructions, &data()->vm, &d.e))
			{
				ft_get_oc_p(&data()->vm, &d.e);
				d.pc = ((d.e.pc_turfu / 2) % MEM_SIZE) - proc->pc;
			}
			while (--d.pc > 0 && cxy(&d, (d.e.pc = (d.e.pc + 1) % MEM_SIZE)))
				put_proc_bloc(bloc, &m->scene_img[VM][33], d.x, d.y);
		}
		m->already[(proc->pc)] = 1;
		proc = proc->n;
	}
}
