#ifndef FT_MLX_H
# define FT_MLX_H
/*
 *	Header lié à la gestion de mlx
 */

/* FICHIER FT_MLX_HOOK.C */
int			mouseo_hook(int x, int y, t_data *d);
int			keyr_hook(int key, t_data *d);
int			keyp_hook(int key, t_data *d);
int			mousep_hook(int btn, int x, int y, t_data *d);
int			mouser_hook(int btn, int x, int y, t_data *d);

/* FICHIER FT_MLX_LOOP.C */
int			loop(char etat);
int			loop_hook(t_data *d);
void		loop_vm(t_data *d);

/* FICHIER FT_MLX_IMG.C */
void		*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file);
int			itow(void *img, int x, int y, char *name);

/* FICHIER FT_MLX_INIT.C */
void		mlx_start(t_data *d, t_dmlx *m);

/* FICHIER FT_MLX_SCENE.C */
void		scene(t_data *d, t_dmlx *m, t_input *i);

/* FICHIER FT_MLX_SCENE_IMG.C */
void		scene_img(t_data *d, t_dmlx *m);

/* FICHIER FT_MLX_SCENE_INTRO.C */
void		scene_intro(t_data *d, t_dmlx *m, t_input *i);

/* FICHIER FT_MLX_DISPLAY.C */
int			display(t_dmlx *m, t_dvm *v);

/* FICHIER FT_MLX_DISPLAY_ARENE.C */
void		display_arene(t_dmlx *m, t_dvm *v, int x, int y);

/* FICHIER FT_MLX_DISPLAY_PROCESSUS.C */
void		display_processus(t_dmlx *m, t_proc *proc, t_img *img);

/* FICHIER FT_MLX_DISPLAY_CYCLE.C */
void		display_ctodie_bar(t_dmlx *m, t_dvm *v, double cycle, int pixel);
void		display_cycle(t_dmlx *m, t_dvm *v);

/* FICHIER FT_MLX_DISPLAY_EFFECT.C */
void		display_effect(t_dmlx *m, t_dvm *v, t_effect *e, int i);

/* FICHIER FT_MLX_EFFECT_INIT.C */
void		effect_init(t_dmlx *m, t_dvm *v, t_effect *e, int i);
t_effect	*effect_data(void);

#endif
