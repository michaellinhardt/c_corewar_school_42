#include "libft.h"
#include "ft_asm.h"

static void	ft_init_instructions_flags_ocp(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
}

static void	ft_init_instructions_flags_a_definir(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 0;
}

void		ft_init_instructions(t_instructions *inst)
{
	ft_init_instructions_name(inst);
	ft_init_instructions_nbr_args(inst);
	ft_init_instructions_types_arg_zero(inst);
	ft_init_instructions_types_arg_un(inst);
	ft_init_instructions_types_arg_deux(inst);
	ft_init_instructions_flags_ocp(inst);
	ft_init_instructions_flags_a_definir(inst);
}
