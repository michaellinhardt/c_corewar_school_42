#include "ft_corewar.h"

void		ft_recup_code(t_dvm *vm, t_dargs *args)
{
	int i;
	ssize_t ret;

	i = 0;
	while (i < vm->nbr_players)
	{
		if ((ret = read(args[i].fd, vm->p[i].code, vm->p[i].header.prog_size))
				== -1)
			exit1(1, data(), "Pb de read fdp");
		if (ret != vm->p[i].header.prog_size)
			exit1(1, data(), "Batard pas la bonne taille");
		vm->p[i].playing = 1;
		++i;
	}
}
