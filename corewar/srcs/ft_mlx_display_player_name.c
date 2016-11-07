#include "ft_corewar.h"

void		display_player_name(t_dmlx *m, t_dvm *v)
{
	int		i;
	char	s[3];

	i = -1;
	s[1] = ' ';
	s[2] = '\0';
	while (++i < MAX_PLAYERS)
	{
		if (!v->p[i].playing)
			continue ;
		s[0] = (i + 1) + '0';
		mlx_string_put(m->mlx, m->win, PLAYERNUMBERX
		, PLAYERNAMEY + (i * PLAYERNAMEYINC), TXTCOLPROCTOTAL, s);
		mlx_string_put(m->mlx, m->win, PLAYERNAMEX
		, PLAYERNAMEY + (i * PLAYERNAMEYINC), TXTCOLPROCTOTAL
		, v->p[i].header.prog_name);
	}
}
