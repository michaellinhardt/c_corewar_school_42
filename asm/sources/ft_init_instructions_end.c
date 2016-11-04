#include "ft_asm.h"

void	ft_init_instructions_types_arg_deux(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_DIR | T_REG;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = T_REG;
}
