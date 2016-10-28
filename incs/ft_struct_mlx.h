#ifndef FT_STRUCT_MLX_H
# define FT_STRUCT_MLX_H
# define CPERLOOP_NUMBER 12

enum	e_scene {
	INTRO,
	VM_INIT,
	VM
};

typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				end;
	int				i;
}					t_img;

enum	e_effect_id {
	e_effect_cperloop
};

typedef struct		s_effect
{
	char			id_effect;
	char			id_max;
	char			i;
	struct s_img	*img;
	int				looptodie;
	int				looptodie_count;
	char			inc_value;
	char			start_cycle;
	int				size_x;
	int				size_y;
	int				fade;
	int				x;
	int				y;
}					t_effect;

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
	t_effect		*effect;
	char			loop;
	char			loopstop;
	enum e_scene	scene;
	char			img_isload[SCENE_MAX];
	t_img			scene_img[SCENE_MAX][SCENE_IMG_MAX];
	char			already[MEM_SIZE];
}					t_dmlx;

#endif
