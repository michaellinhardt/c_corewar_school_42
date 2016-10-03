#include "ft_corewar.h"

void	ft_put_registre(char *arene, unsigned int code, int pc)
{
	unsigned int base;
	unsigned int chiffre;

	base = 268435456;
	while (base)
	{
			chiffre = code / base;
			code = code - chiffre * base;
			if (chiffre > 9)
				*(arene + pc % SIZE_CHAR_ARENE) = chiffre + 55;
			else
				*(arene + pc % SIZE_CHAR_ARENE) = chiffre + '0';
			++pc;
		base = base / 16;
	}
}
