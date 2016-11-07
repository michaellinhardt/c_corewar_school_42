#include "ft_corewar.h"

void	ft_display_vm_papy(t_dvm *vm)
{
	int		i;

	i = 0;
	while (i < SIZE_CHAR_ARENE)
	{
		if (!(i % 128))
			ft_put_hex_compteur(i / 2);
		if (*(vm->arene + i) >= 65)
			ft_putchar(*(vm->arene + i) + 32);
		else
			ft_putchar(*(vm->arene + i));
		++i;
		if (!(i % 2))
			ft_putchar(' ');
		if (!(i % 128))
			ft_putchar('\n');
	}
}
