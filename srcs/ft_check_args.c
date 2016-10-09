#include "ft_corewar.h"

int		ft_check_value_args(t_argument *args, t_instructions *inst, t_dvm *vm,
		t_proc *proc)
{
	int i;

	i = 0;
	ft_get_oc_p(vm, proc);
	while (i < MAX_ARGS_NUMBER)
	{
		if (args[i].type == REG_CODE && ((0x01 & inst->types[i]) != 0x01))
		{
			return (0);
		}
		else if (args[i].type == DIR_CODE  && ((0x02 & inst->types[i]) != 0x02))
		{
			return (0);
		}
		else if (args[i].type == IND_CODE  && ((0x04 & inst->types[i]) != 0x04))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
