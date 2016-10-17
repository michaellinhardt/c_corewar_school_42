#ifndef FT_MLX_H
# define FT_MLX_H

int		mouseo_hook(int x, int y, t_data *d);
int		keyr_hook(int key, t_data *d);
int		keyp_hook(int key, t_data *d);
int		mousep_hook(int btn, int x, int y, t_data *d);
int		mouser_hook(int btn, int x, int y, t_data *d);
int		loop(char etat);
int		loop_hook(t_data *d);
void	loop_vm(t_data *d);
void	*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file);
int		itow(void *img, int x, int y, char *name);
void	mlx_start(t_data *d, t_dmlx *m);
void	scene(t_data *d, t_dmlx *m, t_input *i);
void	scene_img(t_data *d, t_dmlx *m);
void	scene_intro(t_data *d, t_dmlx *m, t_input *i);
int		display(t_dmlx *m, t_dvm *v);
void	display_arene(t_dmlx *m, t_dvm *v, int x, int y);
void	display_processus(t_dmlx *m, t_proc *proc, t_img *img);

#endif
