#include "ft_corewar.h"
#include <fcntl.h>

void	ft_recup_files(t_dvm *vm, t_dargs *args)
{
	int 	i;
	char	*message;

	i = 0;
	(void)vm;
	(void)args;
	message = 0;

	while (i < vm->nbr_players)
	{
		//args->file[i - 1] = argv[i];
		if ((args[i].fd = open(args[i].file, O_RDONLY)) == -1)
		{
			ascii(ASC_EXIT_1);
			message = ft_strjoin("Can't open this fucking file :", args[i].file);
			free_data(data());
			exitascii(data(), 1, message);
			free(message);
			exit(1);
		}
		++i;
	}
}
