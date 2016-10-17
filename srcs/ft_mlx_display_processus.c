#include "ft_corewar.h"

void	reset_img(t_img *img)
{
	int		*ptr;

	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = 0xFF000000;
}

void	put_proc_img(t_img *img, t_img *proc, int x, int y)
{
	int		*pproc;
	int		*pimg;

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
	int		x;
	int		y;

	reset_img(img);
	while (proc)
	{
		x = (proc->pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
		y = (proc->pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
		put_proc_img(img, &m->scene_img[2][-proc->player + 5], x, y);
		proc = proc->n;
	}
	itow(m->scene_img[2][10].img, 0, 0, "processus layer");
}
