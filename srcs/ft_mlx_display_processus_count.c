/*
** GENERE L'AFFICHAGE DU COMPTE DES PROCESSUS
*/
#include "ft_corewar.h"

void	display_processus_number(t_dmlx *m, t_dvm *v)
{
	char	txt[500];

	mlx_string_put(m->mlx, m->win, TXTPROCTOTALX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->nbr_proc))) / 2) * TXTDECALLAGEX)
	, TXTPROCTOTALY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP1X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[0].total_proc_alive))) / 2) * TXTDECALLAGEX)
	, TXTPROCP1Y, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP2X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[1].total_proc_alive))) / 2) * TXTDECALLAGEX)
	, TXTPROCP2Y, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP3X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[2].total_proc_alive))) / 2) * TXTDECALLAGEX)
	, TXTPROCP3Y, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP4X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[3].total_proc_alive))) / 2) * TXTDECALLAGEX)
	, TXTPROCP4Y, TXTCOLPROCTOTAL, txt);
}

void	display_processus_count(t_dmlx *m, t_dvm *v)
{
	display_processus_number(m, v);
}
