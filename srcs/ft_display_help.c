#include "ft_corewar.h"

void	ft_display_help(void)
{
	ft_putendl("  -dump [cycle]\t\tstop at [cycle] and display memory state");
	ft_putendl("  -p \tforce pause at start");
	ft_putendl("  -n [number 1-4]\tforce next champion number");
	ft_putendl("  -v [number]\t\tlog like zaz to check diff");
	ft_putendl("  -g [number]\t\tforce graphic mode regardless to header");
	ft_putendl("  -l [number]\t\tforce colored log in terminal");
	exit(0);
}
