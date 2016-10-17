#include "ft_corewar.h"

int		ft_get_indirect(int pc, t_dvm *vm)
{
	t_argument arg;
	
	arg.value = 0;
	pc = ft_convert_pc(pc);
	ft_fill_args_dir(&arg, vm, (pc * 2) % SIZE_CHAR_ARENE);
	return (arg.value);
}
