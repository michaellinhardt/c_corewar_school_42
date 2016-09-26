#include "ft_corewar.h"
#include <fcntl.h>

void	ft_recup_files(t_dvm *vm, t_dargs *args, char **argv, int argc)
{
	int 	i;
	char	*message;

	i = 1;
	if (argc > 5)
		exit1(1, data(), "Too many champions mother Fucker");
	else if (argc == 1)
		exit1(1, data(), "Entre un champion a minima Enculee");
	while (i < argc)
	{
		args->file[i - 1] = argv[i];
		if ((args->fd[i - 1] = open(argv[i], O_RDONLY)) == -1)
		{
			ascii(ASC_EXIT_1);
			message = ft_strjoin("Can't open this fucking file :", argv[i]);
			free_data(data());
			exitascii(data(), 1, message);
			free(message);
			exit(1);
		}
		++i;
	}
	vm->nbr_players = i - 1;
}
