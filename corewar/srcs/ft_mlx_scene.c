#include "ft_corewar.h"

void		ft_init_music(t_dvm *vm, int off)
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
}

void		ft_music_start(t_dvm *vm, int off)
{
	if (!off)
	{
		ft_init_music(vm, 0);
		vm->son = Mix_LoadMUS("./music/halo.mp3");
		Mix_PlayMusic(vm->son, -1);
	}
	if (off == 1)
	{
		ft_init_music(vm, 1);
		vm->son = Mix_LoadMUS("./music/paranoid.mp3");
		Mix_PlayMusic(vm->son, -1);
	}
	if (off == 2)
	{
		ft_init_music(vm, 1);
		vm->son = Mix_LoadMUS("./music/sail.mp3");
		Mix_PlayMusic(vm->son, -1);
	}
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
	{
		ft_music_start(&d->vm, 1);
		intro_out(d, &m->scene_img[0][0], &m->scene_img[0][1]
			, &m->scene_img[0][3]);
	}
	else if (m->scene == END)
		vm_end(m, &data()->vm, &m->scene_img[0][0]);
}
