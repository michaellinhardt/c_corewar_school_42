#ifndef FT_MLX_H
# define FT_MLX_H
/*
 *	Header lié à la gestion de mlx
 */

/* FICHIER FT_MLX_HOOK.C */
int		mouseo_hook(int x, int y, t_data *d);
int		keyr_hook(int key, t_data *d);
int		keyp_hook(int key, t_data *d);
int		mousep_hook(int btn, int x, int y, t_data *d);
int		mouser_hook(int btn, int x, int y, t_data *d);

/* FICHIER FT_MLX_LOOP.C */
int		loop(char etat);
int		loop_hook(t_data *d);

/* FICHIER FT_MLX_IMG.C */
void	*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file);

/* FICHIER FT_MLX_INIT.C */
void	mlx_start(t_data *d, t_dmlx *m);

/* FICHIER FT_MLX_SCENE.C */
void	scene(t_data *d, t_dmlx *m, t_input *i);

/* FICHIER FT_MLX_SCENE_IMG.C */
void	scene_img(t_data *d, t_dmlx *m);

/* FICHIER FT_MLX_SCENE_INTRO.C */
void	scene_intro(t_data *d, t_dmlx *m, t_input *i);

#endif
