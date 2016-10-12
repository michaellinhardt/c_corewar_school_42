/*
** GENERE L'AFFICHAGE DES PROCESSUS
*/
#include "ft_corewar.h"

void	put_proc_img(t_img *img, t_img *proc, int x, int y)
{
	int			*pproc;
	int			*pimg;

	pproc = (int *)proc->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < PROCY)
	{
		x = -1;
		while (++x < PROCX)
		{
			pimg[++(img->i)] = pproc[y * PROCX + x];
		}
		img->i = img->i - x + WIN_X;
	}
}

void	display_processus(t_dmlx *m, t_proc *proc, t_img *img)
{
	char		already[MEM_SIZE];
	int			x;
	int			y;

	ft_bzero(already, sizeof(already));
	while ( proc )
	{
		if (already[(proc->pc)])
		{
			proc = proc->n;
			continue ;
		}
		x = (proc->pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
		y = (proc->pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
		put_proc_img(img, &m->scene_img[2][-proc->player + 5], x, y);
		already[(proc->pc)] = 1;
		proc = proc->n;
	}
}
