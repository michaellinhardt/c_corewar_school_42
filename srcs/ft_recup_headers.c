#
#include "ft_corewar.h"

void		ft_recup_headers(t_dvm *vm, t_dargs *args)
{
	int i;
	
	i = 0;
	while (i < vm->nbr_players)
	{
		read(args->fd[i], (void *)&vm->p->header, sizeof(header_t));
		++i;
	}
}
