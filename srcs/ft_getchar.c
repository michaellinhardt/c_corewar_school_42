#include "ft_corewar.h"

char	ft_getchar(char *arene)
{
	unsigned char ret;

	ret = 0;
	if (*arene < 58)
		ret = (*(arene) - 48) * 16;
	else
		ret = (*(arene) - 55) * 16;
	if (*(arene + 1) < 58)
		ret += (*(arene + 1) - 48);
	else
		ret += (*(arene + 1) - 55);
	return ((char)ret);
}
