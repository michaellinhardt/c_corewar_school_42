/*
** GENERE L'AFFICHAGE DES BAR DE LIVE
*/
#include "ft_corewar.h"

static void	put_open_img_4(t_img *img, t_img *open, int x, int y)
{
	int			*popen;
	int			*pimg;

	popen = (int *)open->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < BAROPENY)
	{
		x = -1;
		while (++x < BAROPENX)
		{
			pimg[++(img->i)] = popen[y * BAROPENX + x];
			img->str[img->i * 4 + 3] = BARLIVE2PROCALPHA;
		}
		img->i = img->i - x + WIN_X;
	}
}

static void	put_close_img_4(t_img *img, t_img *open, int x, int y)
{
	int			*popen;
	int			*pimg;

	popen = (int *)open->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < BARCLOSEY)
	{
		x = -1;
		while (++x < BARCLOSEX)
		{
			pimg[++(img->i)] = popen[y * BARCLOSEX + x];
			img->str[img->i * 4 + 3] = BARLIVE2PROCALPHA;
		}
		img->i = img->i - x + WIN_X;
	}
}

void		display_bar_proc_live_current(t_dmlx *m,
			t_dvm *v, t_img *img, int i)
{
	int		popen;
	int		pclose;
	int		lastlivex;

	i = -1;
	popen = -1;
	pclose = -1;
	while (++i < MAX_PLAYERS)
		if (v->p[i].total_live_current > 0 && ((pclose = i) + 1) && popen == -1)
			popen = i;
	put_open_img_4(img, &m->scene_img[VM][BARIMGID + (popen * 3)]
			, BARPROCALIVEX, BARPROCALIVEY + BARPROCLIVE2INCY);
	put_mid_img_4(v, img, -1, -1);
	put_close_img_4(img, &m->scene_img[VM][BARIMGID + (pclose * 3) + 2]
			, BARPROCALIVEX + BARPROCALIVESIZE,
			BARPROCALIVEY + BARPROCLIVE2INCY);
	lastlivex = (ABS(v->last_live));
}
