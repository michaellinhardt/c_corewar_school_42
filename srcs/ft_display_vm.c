#include "ft_corewar.h"

void	ft_put_hex_cpt(int i)
{
	if (i > 15)
		ft_put_hex_cpt(i / 16);
	if (i % 16 < 10)
		ft_putchar(i % 16 + '0');
	else
		ft_putchar(i % 16 + 87);
}

void	ft_put_hex_compteur(int i)
{
	(void)i;
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

void	ft_put_color(int *color)
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

// #debug
void	ft_display_vm_papy(t_dvm *vm)
{
	int i;

	i = 0;
	t_proc *proc;
	while (i < SIZE_CHAR_ARENE)
	{
	proc = vm->proc;
		while (proc)
		{
			if (proc->id == 3 && proc->pc == i / 2)
			{
	   			ft_putstr(YELLOW);
				break;
			}
			proc = proc->n;
		}
		if (!(i % 128))
			ft_put_hex_compteur(i / 2);
		if (*(vm->arene + i) >= 65)
			ft_putchar(*(vm->arene + i) + 32);
		else
			ft_putchar(*(vm->arene + i));
		++i;
		if (!(i % 2))
			ft_putchar(' ');
		if (!(i % 128))
			ft_putchar('\n');
		ft_putstr(WHITE);
	}


}

void	ft_display_vm(t_dvm *vm)
{
//	ft_display_vm_papy(vm);
	   int i;
	   int ok;
	   t_proc *proc;

	   i = 0;
	   while (i < SIZE_CHAR_ARENE)
	   {
	   ok = 0;
	   proc = vm->proc;
	   while (proc)
	   {
	   if (proc->pc == i / 2 && !(i % 2))
	   {
	   ok = 1;
	   ft_putstr(YELLOW);
	   }
	   proc = proc->n;
	   }
	   if (!(i % 128) && !ok)
	   {
	   ft_putstr(WHITE);
	   ft_put_hex_compteur(i / 2);
	   }
	   else if (!(i % 128))
	   ft_put_hex_compteur(i / 2);
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
