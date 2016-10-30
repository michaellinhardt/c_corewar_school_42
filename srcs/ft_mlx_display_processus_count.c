/*
** GENERE L'AFFICHAGE DU COMPTE DES PROCESSUS
*/
#include "ft_corewar.h"

void	display_processus_live_number(t_dmlx *m, t_dvm *v)
{
	char	txt[500];

	mlx_string_put(m->mlx, m->win, TXTPROCTOTALX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->total_live))) / 2) * TXTDECALLAGEX)
	, TXTPROCTOTALY + TXTPROCLIVEINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP1X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[0].total_live))) / 2) * TXTDECALLAGEX)
	, TXTPROCP1Y + TXTPROCLIVEINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP2X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[1].total_live))) / 2) * TXTDECALLAGEX)
	, TXTPROCP2Y + TXTPROCLIVEINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP3X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[2].total_live))) / 2) * TXTDECALLAGEX)
	, TXTPROCP3Y + TXTPROCLIVEINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP4X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[3].total_live))) / 2) * TXTDECALLAGEX)
	, TXTPROCP4Y + TXTPROCLIVEINCY, TXTCOLPROCTOTAL, txt);
}

void	display_processus_live_current_number(t_dmlx *m, t_dvm *v)
{
	char	txt[500];

	mlx_string_put(m->mlx, m->win, TXTPROCTOTALX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->nbr_live_current))) / 2) * TXTDECALLAGEX)
	, TXTPROCTOTALY + TXTPROCLIVE2INCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP1X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[0].total_live_current))) / 2) * TXTDECALLAGEX)
	, TXTPROCP1Y + TXTPROCLIVE2INCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP2X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[1].total_live_current))) / 2) * TXTDECALLAGEX)
	, TXTPROCP2Y + TXTPROCLIVE2INCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP3X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[2].total_live_current))) / 2) * TXTDECALLAGEX)
	, TXTPROCP3Y + TXTPROCLIVE2INCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP4X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[3].total_live_current))) / 2) * TXTDECALLAGEX)
	, TXTPROCP4Y + TXTPROCLIVE2INCY, TXTCOLPROCTOTAL, txt);
}

void	display_processus_alive_number(t_dmlx *m, t_dvm *v)
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

void	display_processus_dead_number(t_dmlx *m, t_dvm *v)
{
	char	txt[500];

	mlx_string_put(m->mlx, m->win, TXTPROCTOTALX - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->nbr_proc_dead))) / 2) * TXTDECALLAGEX)
	, TXTPROCTOTALY + TXTPROCDEADINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP1X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[0].total_proc_dead))) / 2) * TXTDECALLAGEX)
	, TXTPROCP1Y + TXTPROCDEADINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP2X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[1].total_proc_dead))) / 2) * TXTDECALLAGEX)
	, TXTPROCP2Y + TXTPROCDEADINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP3X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[2].total_proc_dead))) / 2) * TXTDECALLAGEX)
	, TXTPROCP3Y + TXTPROCDEADINCY, TXTCOLPROCTOTAL, txt);
	mlx_string_put(m->mlx, m->win, TXTPROCP4X - ((ft_strlen(ft_strcpy(txt
	, ft_itoastatic(v->p[3].total_proc_dead))) / 2) * TXTDECALLAGEX)
	, TXTPROCP4Y + TXTPROCDEADINCY, TXTCOLPROCTOTAL, txt);
}

void	display_processus_count(t_dmlx *m, t_dvm *v)
{
	display_processus_alive_number(m, v);
	display_processus_dead_number(m, v);
	display_processus_live_number(m, v);
	display_processus_live_current_number(m, v);
}
