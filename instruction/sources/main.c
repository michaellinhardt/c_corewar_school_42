#include "libft.h"
#include "instructions.h"

int		main(int ac, char **av)
{
	char *vm;
	t_champion	champions[4] = {0};

	vm = ft_create_vm();
	ft_place_champions(vm ,champions ,ft_pars_champs(champions, av, ac));
	ft_display_vm(vm);
	return (0);
}
