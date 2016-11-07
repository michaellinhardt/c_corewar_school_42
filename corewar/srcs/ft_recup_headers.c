#include "ft_corewar.h"

static void	ft_exit_magic_number(char *file)
{
	char	*message;

	free_data(data());
	ascii(ASC_EXIT_1);
	message = ft_strjoin("Invalid file: ", file);
	exitascii(data(), 1, message);
	if (!data()->vm.console)
		ft_printf("%s\n", message);
	free(message);
	exit(1);
}

static void	ft_exit_read(char *file)
{
	char	*message;

	free_data(data());
	ascii(ASC_EXIT_1);
	message = ft_strjoin("Read fail: ", file);
	exitascii(data(), 1, message);
	if (!data()->vm.console)
		ft_printf("%s\n", message);
	free(message);
	exit(1);
}

static void	ft_exit_champ_size(char *file)
{
	char	*message;

	free_data(data());
	ascii(ASC_EXIT_1);
	message = ft_strjoin("Champion size overflow: ", file);
	exitascii(data(), 1, message);
	if (!data()->vm.console)
		ft_printf("%s\n", message);
	free(message);
	exit(1);
}

void		ft_recup_headers(t_dvm *vm, t_dargs *args)
{
	int		i;

	i = 0;
	while (i < vm->nbr_players)
	{
		l1(1, "READ HEADER", args[i].file);
		if ((read(args[i].fd, (void *)&vm->p[i].header,
						sizeof(t_header))) == -1)
			ft_exit_read(args[i].file);
		if ((vm->p[i].header.magic = ft_little_to_big(vm->p[i].header.magic))
				!= COREWAR_EXEC_MAGIC)
			ft_exit_magic_number(args[i].file);
		if ((vm->p[i].header.prog_size =
					ft_little_to_big(vm->p[i].header.prog_size)) >
				CHAMP_MAX_SIZE)
			ft_exit_champ_size(args[i].file);
		++i;
	}
}
