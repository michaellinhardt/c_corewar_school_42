#ifndef FT_STRUCT_MLX_H
# define FT_STRUCT_MLX_H

enum	e_scene {
	INTRO,
	VM_INIT,
	VM
};

enum	e_coord {
	MENU
};

typedef struct		s_mo
{
	int				area[4];
}					t_mo;

typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				end;
	int				i;
}					t_img;

typedef struct		s_input
{
	char			mleft;
	char			mright;
	char			left;
	char			right;
	char			up;
	char			down;
	char			shift;
	int				mo_x;
	int				mo_y;
	int				mr_x;
	int				mr_y;
}					t_input;

typedef struct		s_dmlx
{
	void			*mlx;
	void			*win;
	t_input			input;
	char			loop;
	char			loopstop;
	enum e_scene	scene;
	char			img_isload[SCENE_MAX];
	t_img			scene_img[SCENE_MAX][SCENE_IMG_MAX];
	enum e_coord	coord;
}					t_dmlx;

#endif
