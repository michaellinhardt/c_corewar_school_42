#include "ft_corewar.h"

/*
** AFFICHAGE AU FUR ET A MESURE DES FREE EFFECTUé
*/
int		free_ascii(int ico, char *type, char *info)
{
	wchar_t		uni;
	char		msg[4096];
	char		bar[100];

	if (!data()->vm.console)
		return (1);
	uni = (ico == 1) ? L'✅' : L'❕';
	(ico == 1) ?
	ft_memcpy(msg, "free\0", 8) : ft_memcpy(msg, "-\0", 14);
	ft_memcpy(bar, ((ico == 1) ? LINE_GREEN : LINE_GREY), 13);
	ft_printf(" %C %s %12s %s %-23s %s %-28s %s\e[93m\n", uni, bar, type, bar
	, info, bar, msg, bar);
	return (1);
}

/*
** FONCTION QUI FREE TOUTE LA LISTE DES IMG CHARGé EN MEMOIRE PAR MLX
** Cette fonction log egalement l'action dans le terminal
*/
void	free_img(t_img *img, t_dmlx *m, int i, int j)
{
	while( ++i < SCENE_MAX )
		if (m->img_isload[i] == 1 && (j = -1))
			while( ++j < SCENE_IMG_MAX)
				if ((img = &m->scene_img[i][j]) && img->img)
				{
					if (data()->vm.console)
						ft_printf(
						" %C %s %13s %s %14s[%03d][%03d] %s %-29s %s\e[93m\n"
						, L'✅', LINE_GREEN, "t_img", LINE_GREEN, "img_isload"
						, i, j, LINE_GREEN, "free\0", LINE_GREEN);
					mlx_destroy_image(m->mlx, img->img);
				}
}

/*
** FONCTION QUI FREE TOUTE LA LISTE DES PROCESSUS CRéer
** Cette fonction log egalement l'action dans le terminal
*/
void	free_proc(t_proc *lst, t_proc *destroy, int wich)
{
	int		i;

	i = 0;
	while (lst)
	{
		++i;
		destroy = lst;
		lst = lst->n;
		ft_memdel((void **)&destroy);
	}
	if (data()->vm.console && wich == 1)
		ft_printf(" %C %s %13s %s %-24s %s free %5d struct %11s %s\e[93m\n"
		, L'✅', LINE_GREEN, "t_proc", LINE_GREEN, "d->vm.proc"
		, LINE_GREEN, i, " ", LINE_GREEN);
	else if (data()->vm.console)
		ft_printf(" %C %s %13s %s %-24s %s free %5d struct %11s %s\e[93m\n"
		, L'✅', LINE_GREEN, "t_proc", LINE_GREEN, "d->vm.procdie"
		, LINE_GREEN, i, " ", LINE_GREEN);
}

/* FONCTION APPELLER QUAND ON FERME LE PROGRAMME
 * basiquement .. elles lance tous les free et le log en terminal */
void	free_data(t_data *d)
{
	ascii(ASC_FREEDATA);
	get_next_line(-10, NULL);
	free_img((t_img *)NULL, &d->mlx, -1, -1);
	free_proc(d->proc, (t_proc *)NULL, 1);
	free_proc(d->procdie, (t_proc *)NULL, 2);
}
