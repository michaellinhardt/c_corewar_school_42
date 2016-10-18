#ifndef FT_MLX_H
# define FT_MLX_H

int			mouseo_hook(int x, int y, t_data *d);
int			keyr_hook(int key, t_data *d);
int			keyp_hook(int key, t_data *d);
int			mousep_hook(int btn, int x, int y, t_data *d);
int			mouser_hook(int btn, int x, int y, t_data *d);
int			loop(char etat);
int			loop_hook(t_data *d);
void		loop_vm(t_data *d);
void		*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file);
int			itow(void *img, int x, int y, char *name);
void		mlx_start(t_data *d, t_dmlx *m);
void		scene(t_data *d, t_dmlx *m, t_input *i);
void		scene_img(t_data *d, t_dmlx *m);
void		scene_intro(t_data *d, t_dmlx *m, t_input *i);
int			display(t_dmlx *m, t_dvm *v);
void		display_arene(t_dmlx *m, t_dvm *v, int x, int y);
void		display_processus(t_dmlx *m, t_proc *proc, t_img *img);
int			mouseo_hook(int x, int y, t_data *d);
int			keyr_hook(int key, t_data *d);
int			keyp_hook(int key, t_data *d);
int			mousep_hook(int btn, int x, int y, t_data *d);
int			mouser_hook(int btn, int x, int y, t_data *d);
int			loop(char etat);
int			loop_hook(t_data *d);
void		loop_vm(t_data *d);
void		*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file);
int			itow(void *img, int x, int y, char *name);
void		mlx_start(t_data *d, t_dmlx *m);
void		scene(t_data *d, t_dmlx *m, t_input *i);
void		scene_img(t_data *d, t_dmlx *m);
void		scene_intro(t_data *d, t_dmlx *m, t_input *i);
int			display(t_dmlx *m, t_dvm *v);
void		display_arene(t_dmlx *m, t_dvm *v, int x, int y);
void		display_processus(t_dmlx *m, t_proc *proc, t_img *img);
void		display_processus_count(t_dmlx *m, t_dvm *v);
void		display_ctodie_bar(t_dmlx *m, t_dvm *v, double cycle, int pixel);
void		display_cycle(t_dmlx *m, t_dvm *v);
void		display_bar_proc(t_dmlx *m, t_dvm *v, t_img *img, int i);
void		display_bar_proc_dead(t_dmlx *m, t_dvm *v, t_img *img, int i);
void		display_bar_proc_live(t_dmlx *m, t_dvm *v, t_img *img, int i);
void		display_effect(t_dmlx *m, t_dvm *v, t_effect *e, int i);
void		put_mid_img_3(t_dvm *v, t_img *img, int i, int posx);
t_effect	*effect_data(void);

#endif
