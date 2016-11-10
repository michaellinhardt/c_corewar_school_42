#include "ft_corewar.h"

int		red_cross(void)
{
	t_data *d;

	d = data();
	exit1(0, d, "by clic on red cross");
	return (0);
}

void	mlx_start(t_data *d, t_dmlx *m)
{
	m->mlx = mlx_init();
	ft_music_start(&d->vm, 0);
	m->win = mlx_new_window(m->mlx, WIN_X, WIN_Y, WIN_TITLE);
	l1(10, "D->MLX", "get mlx_init() return");
	l1(10, "D->WIN", "get the mlx_new_window return");
	mlx_hook(m->win, 2, (1L << 0), keyp_hook, d);
	mlx_hook(m->win, 3, (1L << 1), keyr_hook, d);
	mlx_hook(m->win, 4, (1L << 2), mousep_hook, d);
	mlx_hook(m->win, 5, (1L << 3), mouser_hook, d);
	mlx_hook(m->win, 6, (1L << 0), mouseo_hook, d);
	mlx_hook(m->win, 17, (1L << 17), &red_cross, d);
	mlx_loop_hook(m->mlx, loop_hook, d);
	l1(10, "MLX_HOOK", "all hook are initialised");
	l1(10, "EFFECT_INIT", "effect data are initialised");
	loop(0);
	mlx_loop(m->mlx);
}