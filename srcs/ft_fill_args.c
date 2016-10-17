#include "ft_corewar.h"

static int		ft_fill_args_reg(t_argument *arg, const t_dvm *vm, int pc)
{
	arg->value = (unsigned char)ft_getchar(vm->arene + pc);
	pc = (pc + 2) % SIZE_CHAR_ARENE;
	return (pc);
}

int		ft_fill_args_dir(t_argument *arg, const t_dvm *vm, int pc)
{
	int i;
	int decal;

	i = 0;
	decal = 24;
	while (i < 4)
	{
		arg->value |= (unsigned char)ft_getchar(vm->arene + pc) << decal;
		pc = (pc + 2) % SIZE_CHAR_ARENE;
		decal -= 8;
		++i;
	}
	return (pc);
}

int		ft_fill_args_ind(t_argument *arg, const t_dvm *vm, int pc)
{
	int i;
	int decal;

	i = 0;
	decal = 8;
	while (i < 2)
	{
		arg->value |= (unsigned char)ft_getchar(vm->arene + pc) << decal;
		pc = (pc + 2) % SIZE_CHAR_ARENE;
		decal -= 8;
		++i;
	}
	arg->value = (short)arg->value;
	return (pc);
}


int		ft_fill_args(t_argument *arg,const t_dvm *vm, int pc, const t_proc *proc)
{
	int i;


	i = 0;
	while (i < proc->inst->nbr_args)
	{
		arg[i].value = 0;
		if (arg[i].type == REG_CODE)
			pc = ft_fill_args_reg(&arg[i], vm, pc);
		else if (arg[i].type == DIR_CODE && !proc->inst->flag_size_ind)
			pc = ft_fill_args_dir(&arg[i], vm, pc % SIZE_CHAR_ARENE);
		else if (arg[i].type == IND_CODE || arg[i].type == DIR_CODE)
				pc = ft_fill_args_ind(&arg[i], vm, pc);
		if (pc >= SIZE_CHAR_ARENE)
			pc %= SIZE_CHAR_ARENE;
		++i;
	}
	return (pc);
}
