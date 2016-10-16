#include "ft_corewar.h"

int		ft_check_value_args(const t_argument *args, const t_instructions *inst, t_dvm *vm,
		t_proc *proc)
{
	int i;

	i = -1;
	ft_get_oc_p(vm, proc);
	while (++i < proc->inst->nbr_args)
	{
		if (args[i].type == REG_CODE && ((0x01 & inst->types[i]) != 0x01))
			return (0);
		else if (args[i].type == DIR_CODE  && ((0x02 & inst->types[i]) != 0x02))
			return (0);
		else if (args[i].type == IND_CODE  && ((0x04 & inst->types[i]) != 0x04))
			return (0);
		else if (inst->types[i] && !args[i].type)
			return (0);
		else if (!inst->types[i] && args[i].type)
			return (0);
	}
	return (1);
}
