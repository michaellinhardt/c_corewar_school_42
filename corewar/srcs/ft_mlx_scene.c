#include "ft_corewar.h"

int			ft_is_mine(t_dvm *v)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
		if (!ft_strcmp(v->p[i].header.prog_name, "zorkyou"))
			return (1);
		else if (!ft_strcmp(v->p[i].header.prog_name, "brainfuck"))
			return (1);
	return (0);
}

int			ft_init_music(t_dvm *vm, int off)
{
	if (off)
	{
		Mix_FreeMusic(vm->son);
		vm->son = NULL;
	}
	else
	{
		vm->son = NULL;
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			ft_printf("%s", Mix_GetError());
	}
	return (1);
}

void		ft_music_start(t_dvm *vm, int off)
{
	if (!data()->mlx.sound)
		return ;
	else if (!off && data()->mlx.sound == 1 && ft_init_music(vm, 0))
		vm->son = Mix_LoadMUS("./music/halo.mp3");
	else if (!off && data()->mlx.sound == 2 && ft_init_music(vm, 0))
		vm->son = Mix_LoadMUS("./music/ff7_prelude.mp3");
	else if (off == 1 && data()->mlx.sound == 1 && ft_init_music(vm, 1))
		vm->son = Mix_LoadMUS("./music/paranoid.mp3");
	else if (off == 1 && data()->mlx.sound == 2 && ft_is_mine(vm)
	&& ft_init_music(vm, 1))
		vm->son = Mix_LoadMUS("./music/ff7_boss.mp3");
	else if (off == 1 && data()->mlx.sound == 2 && !ft_is_mine(vm)
	&& ft_init_music(vm, 1))
		vm->son = Mix_LoadMUS("./music/ff7_fighting.mp3");
	else if (off == 2 && data()->mlx.sound == 1 && ft_init_music(vm, 1))
		vm->son = Mix_LoadMUS("./music/sail.mp3");
	else if (off == 2 && data()->mlx.sound == 2 && ft_init_music(vm, 1))
		vm->son = Mix_LoadMUS("./music/ff7_victory.mp3");
	Mix_PlayMusic(vm->son, -1);
}

void		scene(t_data *d, t_dmlx *m)
{
	if (m->scene == VM)
		vm(&d->vm, d->vm.cperloop);
	else if (m->scene == VM_INIT)
		vm_init(d, &d->vm);
	else if (m->scene == INTRO_LOAD)
		intro_load(m, &m->scene_img[0][0], &m->scene_img[0][1]);
	else if (m->scene == INTRO_MENU)
		intro_menu(&m->scene_img[0][2], &m->scene_img[0][1]);
	else if (m->scene == INTRO_OUT)
		intro_out(d, &m->scene_img[0][0], &m->scene_img[0][1]
			, &m->scene_img[0][3]);
	else if (m->scene == END)
		vm_end(m, &data()->vm, &m->scene_img[0][0]);
}
