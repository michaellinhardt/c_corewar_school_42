#include "libft.h"
#include "ft_asm.h"

void	ft_init_instructions_name(t_instructions *inst)
{
	ft_memcpy(inst[1].name, "live", 4);
	ft_memcpy(inst[2].name, "ld", 2);
	ft_memcpy(inst[3].name, "st", 2);
	ft_memcpy(inst[4].name, "add", 3);
	ft_memcpy(inst[5].name, "sub", 3);
	ft_memcpy(inst[6].name, "and", 3);
	ft_memcpy(inst[7].name, "or", 2);
	ft_memcpy(inst[8].name, "xor", 3);
	ft_memcpy(inst[9].name, "zjmp", 4);
	ft_memcpy(inst[10].name, "ldi", 3);
	ft_memcpy(inst[11].name, "sti", 3);
	ft_memcpy(inst[12].name, "fork", 4);
	ft_memcpy(inst[13].name, "lld", 3);
	ft_memcpy(inst[14].name, "lldi", 4);
	ft_memcpy(inst[15].name, "lfork", 5);
	ft_memcpy(inst[16].name, "aff", 3);
}

void	ft_init_instructions_nbr_args(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].nbr_args = 1;
	inst[i++].nbr_args = 2;
	inst[i++].nbr_args = 2;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 1;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 1;
	inst[i++].nbr_args = 2;
	inst[i++].nbr_args = 3;
	inst[i++].nbr_args = 1;
	inst[i++].nbr_args = 1;
}

void	ft_init_instructions_types_arg_zero(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].types[0] = T_DIR;
	inst[i++].types[0] = T_DIR | T_IND;
	inst[i++].types[0] = T_REG;
	inst[i++].types[0] = T_REG;
	inst[i++].types[0] = T_REG;
	inst[i++].types[0] = T_REG | T_DIR | T_IND;
	inst[i++].types[0] = T_REG | T_DIR | T_IND;
	inst[i++].types[0] = T_REG | T_DIR | T_IND;
	inst[i++].types[0] = T_DIR;
	inst[i++].types[0] = T_REG | T_DIR | T_IND;
	inst[i++].types[0] = T_REG;
	inst[i++].types[0] = T_DIR;
	inst[i++].types[0] = T_DIR | T_IND;
	inst[i++].types[0] = T_REG | T_DIR | T_IND;
	inst[i++].types[0] = T_DIR;
	inst[i++].types[0] = T_REG;
}

void	ft_init_instructions_types_arg_un(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].types[1] = 0;
	inst[i++].types[1] = T_REG;
	inst[i++].types[1] = T_IND | T_REG;
	inst[i++].types[1] = T_REG;
	inst[i++].types[1] = T_REG;
	inst[i++].types[1] = T_REG | T_DIR | T_IND;
	inst[i++].types[1] = T_REG | T_DIR | T_IND;
	inst[i++].types[1] = T_REG | T_DIR | T_IND;
	inst[i++].types[1] = 0;
	inst[i++].types[1] = T_DIR | T_REG;
	inst[i++].types[1] = T_REG | T_DIR | T_IND;
	inst[i++].types[1] = 0;
	inst[i++].types[1] = T_REG;
	inst[i++].types[1] = T_REG | T_DIR;
	inst[i++].types[1] = 0;
	inst[i++].types[1] = 0;
}
