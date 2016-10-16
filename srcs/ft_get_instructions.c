#include "ft_corewar.h"

static int ft_get_pc_turfu(t_argument *arg, t_instructions *inst, int pc)
{
	int i;

	i = 0;
	while (i < inst->nbr_args)
	{
		if (arg[i].type == REG_CODE)
			pc += 2;
		else if (arg[i].type == DIR_CODE && !inst->flag_size_ind)
			pc += 8;
		else if (arg[i].type == IND_CODE || arg[i].type == DIR_CODE)
			pc += 4;
		++i;
		pc %= SIZE_CHAR_ARENE;
	}
	return (pc % SIZE_CHAR_ARENE);

}	

void		ft_get_oc_p(const t_dvm *vm, t_proc *proc)
{
	unsigned char	oc_p;

	if (proc->inst->flag_ocp)
	{
		oc_p = (unsigned char)ft_getchar(vm->arene + ((proc->pc + 1) * 2)
				% SIZE_CHAR_ARENE);
		ft_decode_args(oc_p, proc->args);
		proc->pc_turfu += 2;
	}
	else
		ft_no_ocp(proc->args, proc->inst->types);
	ft_fill_args(proc->args, vm, proc->pc_turfu % SIZE_CHAR_ARENE, 
			proc); 
	proc->pc_turfu = ft_get_pc_turfu(proc->args, proc->inst, proc->pc_turfu);
}

int		ft_get_instruction(t_instructions *inst, const t_dvm *vm, t_proc *proc)
{
	char	opcode;

	opcode = ft_getchar(vm->arene + (proc->pc * 2) % SIZE_CHAR_ARENE);
	proc->pc_turfu += 2;
	if (proc->pc_turfu >= SIZE_CHAR_ARENE)
		proc->pc_turfu %= SIZE_CHAR_ARENE;
	if (opcode <= 0 || opcode > 16)
	{
		proc->inst = (void *)0;
		return (0);
	}
	proc->inst = &inst[(int)opcode];
	proc->inst->id = (int)opcode;
	proc->wait = proc->inst->cycles;
	return (1);
}
