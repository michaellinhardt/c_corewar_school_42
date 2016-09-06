#include "libft.h"
#include "op.h"

static void	ft_put_hex(unsigned char nbr)
{
//	ft_putnbr(nbr);
	if (nbr >= 16)
		ft_put_hex(nbr / 16);
	if (nbr % 16 < 10)
		ft_putchar('0' + nbr % 16);
	else
		ft_putchar('A' + nbr % 16 - 10);
}

static void	ft_putnbr_hex(unsigned char nbr)
{
	if (nbr < 16)
		ft_putchar('0');
	ft_put_hex(nbr);
}

void	ft_display_vm(char *vm)
{
	unsigned int size;

	size = 0;

	while (size < MEM_SIZE)
	{
		ft_putnbr_hex(*(vm +size));
		++size;
		if (!(size % 64))
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}
