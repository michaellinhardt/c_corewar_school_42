#include "ft_corewar.h"
#include <fcntl.h>

void	ft_recup_files(t_dvm *vm, t_dargs *args)
{
	int		i;
	char	*message;

	i = 0;
	message = 0;
	while (i < vm->nbr_players)
	{
		l1(1, "OPEN FILE", args[i].file);
		if ((args[i].fd = open(args[i].file, O_RDONLY)) == -1)
		{
			message = ft_strjoin("Can't open this fucking file: ",
					args[i].file);
			if (!vm->console)
				ft_printf("%s\n", message);
			free_data(data());
			ascii(ASC_EXIT_1);
			exitascii(data(), 1, message);
			free(message);
			exit(1);
		}
		++i;
	}
}
