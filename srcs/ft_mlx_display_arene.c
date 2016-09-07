/*
** GENERE L'AFFICHAGE DE LARENE UNIQUEMENT
*/
#include "ft_corewar.h"

void	display_arene(t_dmlx *m, t_dvm *v, int x, int y)
{
	int		i;
	char	s[3];

	i = 0;
	s[2] = '\0';
	while (i < SIZE_CHAR_ARENE - 1)
	{
		s[0] = v->arene[i];
		s[1] = v->arene[i + 1];
		// insere le text
		mlx_string_put(m->mlx, m->win, x * VMSPACEBLANK + VMSTARTX
		, y * VMSPACELINE + VMSTARTY, ARENE_CODE_COLOR, s);
		// insere la couleur de fond
		// if (v->code[])
		++x;
		if (x >= VMPERLINE && !(x = 0))
			++y;
		i += 2;
	}
}
