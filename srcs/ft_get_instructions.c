#include "ft_corewar.h"

/*
 ** Return 1 si instructions bonne, return 0 si false
 */

#include <stdio.h>


/*
static void			ft_get_new_turfu(t_dvm *vm, t_proc *proc)
{
	int			oc_p;
	int			i;
	t_argument 	arg[MAX_ARGS_NUMBER];

	ft_bzero(arg, sizeof(arg));
	if (proc->inst->flag_ocp)
	{
		oc_p = ft_getchar(vm->arene + (proc->pc + 1) * 2);
		proc->pc_turfu_past = proc->pc_turfu + 2;
		ft_decode_args(oc_p, arg); 
	}
	else 
	{
		proc->pc_turfu_past = proc->pc_turfu;
		ft_no_ocp(arg, proc->inst->types);
	}
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (arg[i].type == REG_CODE)
			proc->pc_turfu_past = proc->pc_turfu_past + 2;
		else if (arg[i].type == DIR_CODE && !proc->inst->flag_size_ind)
			proc->pc_turfu_past = proc->pc_turfu_past + 8;
		else if (arg[i].type == IND_CODE || arg[i].type == DIR_CODE)
			proc->pc_turfu_past = proc->pc_turfu_past + 4;
		++i;
	}

}
*/

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
//	ft_get_new_turfu(vm, proc);
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
