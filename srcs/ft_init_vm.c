#include "ft_corewar.h"

void	ft_init_vm(t_dvm *vm)
{
	unsigned int i;

	ft_memset(vm->arene, '0', SIZE_CHAR_ARENE);
	vm->code_color[0] = ARENE_CODE_COLOR_WHITE;
	vm->code_color[1] = ARENE_CODE_COLOR_P1;
	vm->code_color[2] = ARENE_CODE_COLOR_P2;
	vm->code_color[3] = ARENE_CODE_COLOR_P3;
	vm->code_color[4] = ARENE_CODE_COLOR_P4;
	i = 0;
	while (i < MEM_SIZE)
		vm->color[i++] = vm->code_color[0];
	ft_fill_arene(vm);
}
