#include "ft_corewar.h"

/*
 ** Return 1 si instructions bonne, return 0 si false
 */

#include <stdio.h>
int		ft_get_instruction(t_instructions *inst, t_dvm *vm, t_proc *proc)
{
	char	opcode;
	int ld_caca = 0;

	opcode = ft_getchar(vm->arene + proc->pc * 2);
	proc->pc_turfu += 2;
	if (opcode <= 0 || opcode > 16)
	{
		proc->inst = (void *)0;
		return (0);
	}
	if (opcode == 2)
		ld_caca = 1;
	proc->inst = &inst[(int)opcode];
	proc->wait = proc->inst->cycles;
	if (proc->inst->flag_ocp)
	{
		opcode = (unsigned char)ft_getchar(vm->arene + (proc->pc + 1) * 2);
		ft_decode_args(opcode, proc->args);
		proc->pc_turfu += 2;
	}
	else
		ft_no_ocp(proc->args, proc->inst->types);
	proc->pc_turfu = ft_fill_args(proc->args, vm, proc->pc_turfu, 
			proc->inst->flag_size_ind); 
	if (ld_caca)
	{

		printf("hello fill args %u\n", proc->args[0].value);
		ld_caca = 0;
	}
	return (1);
}
