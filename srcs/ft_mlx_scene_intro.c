#include "ft_corewar.h"

// void	intro_out_fade(t_img *i, int fade)
// {
// 	i->i = -4;
// 	while ((i->i += 4) < (i->sl * WIN_Y))
// 	{
// 		i->str[i->i] = 0;
// 		i->str[i->i + 1] = 0;
// 		i->str[i->i + 2] = 0;
// 		i->str[i->i + 3] = fade;
// 	}
// }
//
// void	intro_out(t_data *d, t_img *i, t_img *l, t_img *p)
// {
// 	static int	fade = 255;
//
// 	if (fade == 255 && !mlx_destroy_image(d->mlx, p->img)
// 								&& !(p->img = (void *)NULL))
// 		p->str = (char *)NULL;
// 	fade -= 5;
// 	if (fade == -5 && !mlx_destroy_image(d->mlx, p->img)
// 								&& !(p->img = (void *)NULL))
// 	{
// 		p->str = (char *)NULL;
// 		d->scene = MAIN_LOAD;
// 		fade = 255;
// 		return ;
// 	}
// 	else if (!(p->img))
// 		p->img = xtoi(p, XPM_PRESSANY2);
// 	intro_out_fade(i, fade);
// 	itow(l->img, 0, 0, "intro logo");
// 	itow(p->img, 500, 455, "press any key red");
// 	itow(i->img, 0, 0, "fade out");
// }
//
// void	intro_menu(t_img *i, t_img *l)
// {
// 	static int	fade = 255;
// 	static int	dir = 6;
//
// 	if ((fade += dir) && fade >= 255)
// 		dir = -6;
// 	else if (fade <= 1)
// 		dir = 6;
// 	fade = (fade < 0) ? 0 : fade;
// 	fade = (fade > 255) ? 255 : fade;
// 	if (!(i->img))
// 		i->img = xtoi(i, XPM_PRESSANY);
// 	i->i = -4;
// 	while ((i->i += 4) < (i->sl * 22))
// 		i->str[i->i + 3] = fade;
// 	itow(l->img, 0, 0, "press any key white");
// 	itow(i->img, 500, 455, "press any key blink");
// }

void	intro_load(t_dmlx *m, t_img *i, t_img *l)
{
	static int	fade = 0;

	itow(l->img, 0, 0, "intro screen");
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 255;
		i->str[i->i + 1] = 255;
		i->str[i->i + 2] = 255;
		i->str[i->i + 3] = fade;
	}
	fade += ((fade + INTRO_FADE_SPEED) < 255) ? INTRO_FADE_SPEED : (fade * -1);
	(fade == 0) ? (m->scene = VM_INIT) : 1;
	itow(i->img, 0, 0, "fade in");
}
