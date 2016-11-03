#include "ft_corewar.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include <stdio.h>

static void	ft_recup_options_players(t_data *d, char **argv, int argc)
{
	d->args[0].player = -1;
	d->args[1].player = -1;
	d->args[2].player = -1;
	d->args[3].player = -1;
	if (!(ft_recup_options(&d->vm, d->args, argv, argc)))
		exit1(1, d, "Missing options");
	if (d->vm.nbr_players == 0)
		exit1(1, d, "Missing options");
	if (!(ft_check_value_number(d->args, &d->vm)))
		exit1(1, d, "Two players with same number");
}

static void	ft_get_init_players(t_data *d)
{
	int		p;

	p = 0;
	if (!d->vm.console)
		ft_printf("Introducing contestants...\n");
	ft_recup_files(&d->vm, d->args);
	ft_recup_headers(&d->vm, d->args);
	ft_recup_code(&d->vm, d->args);
	ft_init_instructions(d->vm.instructions);
	while (p < d->vm.nbr_players)
	{
		if (!d->vm.console)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				ABS(d->args[p].player), d->vm.p[p].header.prog_size,
				d->vm.p[p].header.prog_name,
				d->vm.p[p].header.comment);
		++p;
	}
}

int			main(int argc, char **argv)
{
	t_data	*d;
	Mix_Music *son;
//	Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV

	son = NULL;
	Mix_AllocateChannels(32); //Allouer 32 canaux
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
		printf("Error %s\n", Mix_GetError());
	son = Mix_LoadMUS("./music/is_this_love.mp3");
//	son = Mix_LoadWAV("./is_this_love.wav"); //Charger un wav dans un pointeur
//	Mix_PlayChannel(1, son, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
	if (!son)
		printf("Error\n");
	Mix_PlayMusic(son, 0);
/*	Mix_FreeChunk(son);//Libération du son 1
	Mix_CloseAudio(); //Fermeture de l'API
	return EXIT_SUCCESS;
*/	d = data();
	d->vm.dump = -1;
	d->vm.console = CONSOLE_LOG;
	d->vm.graphic = d->vm.dump == -1 ? GRAPHIC_MODE : 0;
	if (ascii(ASC_LOGO) && ascii(ASC_INIT) && ascii_init())
		ascii(ASC_LOG);
	ft_recup_options_players(d, argv, argc);
	ft_get_init_players(d);
	if (!d->vm.graphic)
		d->mlx.scene = VM_INIT;
	if (d->vm.graphic)
		mlx_start(d, &d->mlx);
	else
		while (42)
			loop_vm(d);
	(void)d;
	(void)argc;
	(void)argv;
	return (0);
}
