#include "ft_corewar.h"

/*
 ** Return 1 si instructions bonne, return 0 si false
 */

#include <stdio.h>


void		ft_get_oc_p(t_dvm *vm, t_proc *proc)
{
	char	oc_p;
	if (proc->inst->flag_ocp)
	{
		oc_p = (unsigned char)ft_getchar(vm->arene + (proc->pc + 1) * 2);
		ft_decode_args(oc_p, proc->args);
		proc->pc_turfu += 2;
	}
	else
		ft_no_ocp(proc->args, proc->inst->types);
	proc->pc_turfu = ft_fill_args(proc->args, vm, proc->pc_turfu, 
			proc->inst->flag_size_ind); 
}

int		ft_get_instruction(t_instructions *inst, t_dvm *vm, t_proc *proc)
{
	char	opcode;

	opcode = ft_getchar(vm->arene + proc->pc * 2);
	proc->pc_turfu += 2;
	if (opcode <= 0 || opcode > 16)
	{
		proc->inst = (void *)0;
		return (0);
	}
	proc->inst = &inst[(int)opcode];
	proc->inst->id = (int)opcode;
	proc->wait = proc->inst->cycles;
	/*
	if (opcode == 1)
	{
		ft_no_ocp(proc->args, proc->inst->types);
	proc->pc_turfu = ft_fill_args(proc->args, vm, proc->pc_turfu, 
			proc->inst->flag_size_ind); 
	}
	*/
	return (1);
}
