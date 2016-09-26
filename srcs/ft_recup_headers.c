#include "ft_corewar.h"

static void	ft_exit_magic_number(char *file)
{
	char	*message;

	free_data(data());
	ascii(ASC_EXIT_1);
	message = ft_strjoin("Invalid file  :", file);
	exitascii(data(), 1, message);
	free(message);
	exit(1);
}

void		ft_recup_headers(t_dvm *vm, t_dargs *args)
{
	int i;

	i = 0;
	while (i < vm->nbr_players)
	{
		if ((read(args->fd[i], (void *)&vm->p[i].header, sizeof(header_t))) == -1)
			exit1(1, data(), "Pb de read fdp");
		if ((vm->p[i].header.magic = ft_little_to_big(vm->p[i].header.magic))
				!= COREWAR_EXEC_MAGIC)
			ft_exit_magic_number(args->file[i]);
		if ((vm->p[i].header.prog_size = 
					ft_little_to_big(vm->p[i].header.prog_size)) > 
				CHAMP_MAX_SIZE)
			ft_exit_magic_number(args->file[i]);
		++i;
	}
}
