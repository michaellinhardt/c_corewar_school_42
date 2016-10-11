#include "ft_corewar.h"

int		ft_check_value_args(t_argument *args, t_instructions *inst, t_dvm *vm,
		t_proc *proc)
{
	int i;
	int pc;
	int ok;

	pc = proc->pc_turfu + 2;
	i = 0;
	/*
	if (ft_strcmp("live", proc->inst->name))
	*/
		ft_get_oc_p(vm, proc);
		(void)args;
		(void)inst;
		(void)vm;
		(void)proc;
		ok = 0;
	if (proc->inst->flag_ocp)
	{
	while (i < MAX_ARGS_NUMBER )
	{
		if (args[i].type == REG_CODE && ((0x01 & inst->types[i]) != 0x01))
		{
			pc += 2;
				proc->pc_turfu = pc;
				ok = 1;
		}
		else if (args[i].type == DIR_CODE  && ((0x02 & inst->types[i]) != 0x02))
		{
			if (proc->inst->flag_size_ind)
				pc += 4;
			else
				pc += 8;
			proc->pc_turfu = pc; 
				ok = 1;
		}
		else if (args[i].type == IND_CODE  && ((0x04 & inst->types[i]) != 0x04))
		{
			pc += 4;
			proc->pc_turfu = pc; 
				ok = 1;
		}
		else if (inst->types[i] && !args[i].type)
		{
			pc += 2;
			proc->pc_turfu = pc; 
				ok = 1;
		}
		else if (!inst->types[i] && args[i].type)
		{
			pc += 2;
			proc->pc_turfu = pc; 
				ok = 1;
		}
		++i;
	}
	}
	if (ok)
		return (0);
	return (1);
}
