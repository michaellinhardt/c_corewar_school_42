/*
** GENERE L'AFFICHAGE DU COMPTE DES PROCESSUS
*/
#include "ft_corewar.h"

void	display_processus_number(t_dmlx *m, t_dvm *v)
{
	mlx_string_put(m->mlx, m->win, TEXTPROCTOTALX, TEXTPROCTOTALY
		, TXTCOLPROCTOTAL, ft_itoastatic(v->nbr_proc));
	mlx_string_put(m->mlx, m->win, TEXTPROCP1X, TEXTPROCP1Y
		, TXTCOLPROCTOTAL, ft_itoastatic(v->p[0].total_proc_alive));
	mlx_string_put(m->mlx, m->win, TEXTPROCP2X, TEXTPROCP2Y
		, TXTCOLPROCTOTAL, ft_itoastatic(v->p[1].total_proc_alive));
	mlx_string_put(m->mlx, m->win, TEXTPROCP3X, TEXTPROCP3Y
		, TXTCOLPROCTOTAL, ft_itoastatic(v->p[2].total_proc_alive));
	mlx_string_put(m->mlx, m->win, TEXTPROCP4X, TEXTPROCP4Y
		, TXTCOLPROCTOTAL, ft_itoastatic(v->p[3].total_proc_alive));
}

void	display_processus_count(t_dmlx *m, t_dvm *v)
{
	display_processus_number(m, v);
}
