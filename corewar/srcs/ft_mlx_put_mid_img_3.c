#include "ft_corewar.h"

static void	ft_put_barliveprocalpha(t_img *img, int *pimg, int *pmid, int y)
{
	pimg[(img->i)] = pmid[y];
	img->str[img->i * 4 + 3] = BARLIVEPROCALPHA;
	img->i = img->i + WIN_X;
}

void		put_mid_img_3(t_dvm *v, t_img *img, int i, int posx)
{
	int			*pmid;
	int			*pimg;
	double		nbr;
	int			y;
	double		percent;

	pimg = (int *)img->str;
	while (++i < MAX_PLAYERS)
	{
		if (!(v->p[i].total_live))
			continue ;
		pmid = (int *)data()->mlx.scene_img[VM][BARIMGID + (i * 3) + 1].str;
		percent = ((double)v->p[i].total_live / (double)v->total_live);
		nbr = ((double)BARPROCALIVESIZE) * percent;
		while (--nbr > -2 && ++posx <= BARPROCALIVESIZE)
		{
			y = -1;
			img->i = ((BARPROCALIVEY + BARPROCLIVEINCY) * WIN_X)
				+ BARPROCALIVEX + BAROPENX + posx;
			while (++y < BAROPENY)
				ft_put_barliveprocalpha(img, pimg, pmid, y);
		}
	}
}

void		put_mid_img_4(t_dvm *v, t_img *img, int i, int posx)
{
	int			*pmid;
	int			*pimg;
	double		nbr;
	int			y;
	double		percent;

	pimg = (int *)img->str;
	while (++i < MAX_PLAYERS)
	{
		if (!(v->p[i].total_live_current))
			continue ;
		pmid = (int *)data()->mlx.scene_img[VM][BARIMGID + (i * 3) + 1].str;
		percent = ((double)v->p[i].total_live_current /
		(double)v->nbr_live_current);
		nbr = ((double)BARPROCALIVESIZE) * percent;
		while (--nbr > -2 && ++posx <= BARPROCALIVESIZE)
		{
			y = -1;
			img->i = ((BARPROCALIVEY + BARPROCLIVE2INCY) * WIN_X)
				+ BARPROCALIVEX + BAROPENX + posx;
			while (++y < BAROPENY)
				ft_put_barliveprocalpha(img, pimg, pmid, y);
		}
	}
}
