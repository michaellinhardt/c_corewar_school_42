#include "ft_corewar.h"

int		main(void)
{
	ft_printf("start\n");
#ifdef CONSOLE_LOG
	ft_printf("mid\n");
#endif
	ft_printf("end\n");
	return (0);
}
