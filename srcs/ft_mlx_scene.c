#include "ft_corewar.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdlib.h>

void		ft_music_init(t_dvm *vm)
{
/*	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
		ft_printf("Error %s\n", Mix_GetError());
	vm->son[0] = Mix_LoadMUS("./music/halo.mp3");
	vm->son[1] = Mix_LoadMUS("./music/paranoid.mp3");
	vm->son[2] = Mix_LoadMUS("./music/sail.mp3");
	Mix_CloseAudio();
	*/
	vm->son = NULL;
}

void		ft_music_end(t_dvm *vm)
{
	Mix_FreeMusic(vm->son);
	vm->son = NULL;
//	Mix_CloseAudio();
}

void		ft_init_music(t_dvm *vm, int off)
{
	if (off)
		ft_music_end(vm);
	else
	{
		vm->son = NULL;
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
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
		Mix_HaltMusic();
		ft_init_music(vm, 1);
		vm->son = Mix_LoadMUS("./music/paranoid.mp3");
		Mix_PlayMusic(vm->son, -1);
	}
	if (off == 2)
	{
		Mix_HaltMusic();
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
	{
		ft_music_start(&d->vm, 0);
		intro_load(m, &m->scene_img[0][0], &m->scene_img[0][1]);
	}
	else if (m->scene == INTRO_MENU)
		intro_menu(&m->scene_img[0][2], &m->scene_img[0][1]);
	else if (m->scene == INTRO_OUT)
	{
		ft_music_start(&d->vm, 1);
		intro_out(d, &m->scene_img[0][0], &m->scene_img[0][1]
			, &m->scene_img[0][3]);
	}
	else if (m->scene == END)
	{
		ft_music_start(&d->vm, 2);
		vm_end(m, &data()->vm, &m->scene_img[0][0]);
	}
}
