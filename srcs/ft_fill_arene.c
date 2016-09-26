#include "ft_corewar.h"

static void	ft_put_hex_arene(char *arene, unsigned char code)
{
	if (code / 16)
		ft_put_hex_arene(++arene, code / 16);

	if (code % 16 >= 10)
	{
		*arene = (code % 16) + 55;
		ft_putchar((code % 16) + 55);
	}
	else
	{
		ft_putchar((code % 16) + '0');
		*arene = (code % 16) + '0';
	}

}

static void ft_place_champion(char *arene, char *code, int *color, unsigned int
		prog_size)
{
	unsigned int i;
	unsigned int t;

	i = 0;
	t= 0;

	(void)(color);
	while (i < prog_size)
	{
		ft_put_hex_arene(arene + t, (unsigned char) *(code + i));
		++i;
		t += 2;
	}


}

void	ft_fill_arene(t_dvm *vm)
{
	int	i;

	i = 0;
	while (i < vm->nbr_players)
	{
		ft_place_champion(vm->arene + ((i * MEM_SIZE) / vm->nbr_players) * 2,
				vm->p[i].code, vm->color, vm->p[i].header.prog_size);
		++i;
	}

}





/*
#include "libft.h"
#include "instructions.h"

void	ft_place_champions(char *vm, t_champion *champions, int champs)
{
unsigned int nbr;

nbr = 0;
while (nbr < champs)
{
ft_memmove(vm + ((nbr * MEM_SIZE) / champs), champions->prog_size, CHAMP_MAX_SIZE);
++champions;
++nbr;
}
}
*/
