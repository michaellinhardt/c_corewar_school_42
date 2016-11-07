#include "ft_corewar.h"

void		ft_put_hex_cpt(int i)
{
	if (i > 15)
		ft_put_hex_cpt(i / 16);
	if (i % 16 < 10)
		ft_putchar(i % 16 + '0');
	else
		ft_putchar(i % 16 + 87);
}

void		ft_put_hex_compteur(int i)
{
	ft_putstr(WHITE);
	ft_putstr("0x");
	if (i == 0)
		ft_putstr("000");
	else if (i <= 0xF)
		ft_putstr("000");
	else if (i <= 0xFF)
		ft_putstr("00");
	else if (i <= 0xFFF)
		ft_putstr("0");
	ft_put_hex_cpt(i);
	ft_putstr(" : ");
}

void		ft_put_color(int *color)
{
	if (*color == ARENE_CODE_COLOR_WHITE)
		ft_putstr(WHITE);
	else if (*color == ARENE_CODE_COLOR_P1)
		ft_putstr(GREEN);
	else if (*color == ARENE_CODE_COLOR_P2)
		ft_putstr(BLUE);
	else if (*color == ARENE_CODE_COLOR_P3)
		ft_putstr(RED);
	else if (*color == ARENE_CODE_COLOR_P4)
		ft_putstr(CYAN);
}

static int	ft_display_pc(t_dvm *vm, int i)
{
	t_proc	*proc;

	proc = vm->proc;
	while (proc)
	{
		if (proc->pc == i / 2 && !(i % 2))
		{
			ft_putstr(YELLOW);
			return (1);
		}
		proc = proc->n;
	}
	return (0);
}

void		ft_display_vm(t_dvm *vm)
{
	int		i;
	int		ok;

	i = 0;
	while (i < SIZE_CHAR_ARENE)
	{
		if (!(i % 128))
			ft_put_hex_compteur(i / 2);
		ok = ft_display_pc(vm, i);
		if (!(i % 2) && !ok)
			ft_put_color(vm->color + i / 2);
		ft_putchar(*(vm->arene + i));
		++i;
		if (!(i % 2))
			ft_putchar(' ');
		if (!(i % 128))
			ft_putchar('\n');
	}
}
