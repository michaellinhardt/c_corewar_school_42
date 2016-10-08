#include "ft_corewar.h"

void	ft_instructions_sti(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int convert1;
	int convert2;
	(void)vm;
	(void)inst;
	(void)proc;

	if (proc->wait == inst.cycles)
	{
	if (ft_check_value_args(proc->args, &inst))
	{
		if (ft_get_args(proc))
	 	{


			convert1 = ft_convert_pc(proc->args[1].value);
			convert2 = ft_convert_pc(proc->args[2].value);

			if (proc->args[1].type == IND_CODE)
				proc->args[1].value = (convert1 + convert2 ) * 2;
			else
				proc->args[1].value = (convert1 + convert2 + proc->pc) * 2;
			/*
			ft_put_registre(vm->arene, proc->args[0].value , address);
			ft_put_color_size(vm->color, ARENE_CODE_COLOR_P2,
						address / 2, 4);
						*/
			proc->last = 11;
			proc->ok = 1;
		}
	}
	}
	else
	{
		if (proc->ok)
		{
			ft_put_registre(vm->arene, proc->args[0].value , proc->args[1].value);
			ft_put_color_size(vm->color, ARENE_CODE_COLOR_P2,
					proc->args[1].value /2, 4);
		}
		proc->pc = proc->pc_turfu / 2;
	}
	l2(13, "INSTRUCTION", "instruction sti", proc->id);
//	ft_printf("instruction %s\n", inst.name);
}
