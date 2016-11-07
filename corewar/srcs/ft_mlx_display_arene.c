/*
** GENERE L'AFFICHAGE DE LARENE UNIQUEMENT
*/
#include "ft_corewar.h"

void	display_arene(t_dmlx *m, t_dvm *v, int x, int y)
{
	int		i;
	int		color;
	char	s[3];

	i = 0;
	s[2] = '\0';
	while (i < SIZE_CHAR_ARENE - 1)
	{
		s[0] = v->arene[i];
		s[1] = v->arene[i + 1];
		color = (m->already[i / 2]) ? 0x000000 : v->color[i / 2];
		mlx_string_put(m->mlx, m->win, x * VMSPACEBLANK + VMSTARTX
		, y * VMSPACELINE + VMSTARTY, color, s);
		++x;
		if (x >= VMPERLINE && !(x = 0))
			++y;
		i += 2;
	}
}
