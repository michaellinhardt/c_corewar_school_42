#include "ft_corewar.h"

static int		ft_fill_args_reg(t_argument *arg, t_dvm *vm, int pc)
{
	arg->value = ft_getchar(vm->arene + pc);
	pc = (pc + 2) % SIZE_CHAR_ARENE;
	return (pc);
}

static int		ft_fill_args_dir(t_argument *arg, t_dvm *vm, int pc)
{
	int i;
	int decal;

	i = 0;
	decal = 24;
	while (i < 4)
	{
		arg->value |= ft_getchar(vm->arene + pc) << decal;
		pc = (pc + 2) % SIZE_CHAR_ARENE;
		decal -= 8;
		++i;
	}
	return (pc);
}

static int		ft_fill_args_ind(t_argument *arg, t_dvm *vm, int pc)
{
	int i;
	int decal;
	unsigned int t;

	i = 0;
	decal = 8;
	t = 0;
	while (i < 2)
	{
		arg->value |= (unsigned char)ft_getchar(vm->arene + pc) << decal;
		pc = (pc + 2) % SIZE_CHAR_ARENE;
		decal -= 8;
		++i;
	}
	return (pc);
}


int		ft_fill_args(t_argument *arg,t_dvm *vm, int pc, int flag_size_ind)
{
	int i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		arg[i].value = 0;
		if (arg[i].type == T_REG)
			pc = ft_fill_args_reg(&arg[i], vm, pc);
		else if (arg[i].type == T_DIR && !flag_size_ind)
			pc = ft_fill_args_dir(&arg[i], vm, pc);
		else if (arg[i].type == T_IND || arg[i].type == T_DIR)
			pc = ft_fill_args_ind(&arg[i], vm, pc);
		++i;
	}
	return (pc);
}
