#include "ft_corewar.h"

static void	ft_put_hex_arene(char *arene, unsigned char code, int *color,
		unsigned int code_color)
{
	unsigned int base;
	unsigned int chiffre;

	base = 16;
	*color = code_color;
	while (base)
	{
		chiffre = code / base;
		code = code - chiffre * base;
		if (chiffre > 9)
			*arene = chiffre + 55;
		else
			*arene = chiffre + '0';
		++arene;
		base = base / 16;
	}
}

static void	ft_place_champion(char *arene, char *code, int p, t_dvm *vm)
{
	unsigned int i;

	i = 0;
	while (i < vm->p[p].header.prog_size)
	{
		ft_put_hex_arene(arene + i * 2, (unsigned char)*(code + i),
				vm->color + i + ((p * MEM_SIZE) / vm->nbr_players),
				vm->code_color[p + 1]);
		++i;
	}
}

void		ft_fill_arene(t_dvm *vm)
{
	int	i;

	vm->code_color[0] = ARENE_CODE_COLOR_WHITE;
	vm->code_color[1] = ARENE_CODE_COLOR_P1;
	vm->code_color[2] = ARENE_CODE_COLOR_P2;
	vm->code_color[3] = ARENE_CODE_COLOR_P3;
	vm->code_color[4] = ARENE_CODE_COLOR_P4;
	i = 0;
	while (i < MEM_SIZE)
		vm->color[i++] = vm->code_color[0];
	i = 0;
	while (i < vm->nbr_players)
	{
		ft_place_champion(vm->arene + ((i * MEM_SIZE) / vm->nbr_players) * 2,
				vm->p[i].code, i, vm);
		++i;
	}
}
