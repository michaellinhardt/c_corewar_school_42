/*
** GENERE L'AFFICHAGE DES BAR DE LIVE
*/
#include "ft_corewar.h"

static void	put_last_live_img(t_img *img, t_img *last, int x, int y)
{
	int			*plast;
	int			*pimg;

	plast = (int *)last->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < LASTLIVEDISPLAYSIZEY)
	{
		x = -1;
		while (++x < LASTLIVEDISPLAYSIZEX)
			pimg[++(img->i)] = plast[y * LASTLIVEDISPLAYSIZEX + x];
		img->i = img->i - x + WIN_X;
	}
}

static void	put_open_img_3(t_img *img, t_img *open, int x, int y)
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
			img->str[img->i * 4 + 3] = BARLIVEPROCALPHA;
		}
		img->i = img->i - x + WIN_X;
	}
}

static void	put_close_img_3(t_img *img, t_img *open, int x, int y)
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
			img->str[img->i * 4 + 3] = BARLIVEPROCALPHA;
		}
		img->i = img->i - x + WIN_X;
	}
}

void		ft_set_lastlivex(int *lastlivex)
{
	if (*lastlivex == 1)
		*lastlivex = LASTLIVEDISPLAYP1X;
	else if (*lastlivex == 2)
		*lastlivex = LASTLIVEDISPLAYP2X;
	else if (*lastlivex == 3)
		*lastlivex = LASTLIVEDISPLAYP3X;
	else
		*lastlivex = LASTLIVEDISPLAYP4X;
}

void		display_bar_proc_live(t_dmlx *m, t_dvm *v, t_img *img, int i)
{
	int		popen;
	int		pclose;
	int		lastlivex;

	i = -1;
	popen = -1;
	pclose = -1;
	while (++i < MAX_PLAYERS)
		if (v->p[i].total_live > 0 && ((pclose = i) + 1) && popen == -1)
			popen = i;
	put_open_img_3(img, &m->scene_img[2][BARIMGID + (popen * 3)]
			, BARPROCALIVEX, BARPROCALIVEY + BARPROCLIVEINCY);
	put_mid_img_3(v, img, -1, -1);
	put_close_img_3(img, &m->scene_img[2][BARIMGID + (pclose * 3) + 2]
			, BARPROCALIVEX + BARPROCALIVESIZE,
			BARPROCALIVEY + BARPROCLIVEINCY);
	lastlivex = (ABS(v->last_live));
	ft_set_lastlivex(&lastlivex);
	put_last_live_img(img, &m->scene_img[2][25], lastlivex, LASTLIVEDISLAYY);
}
