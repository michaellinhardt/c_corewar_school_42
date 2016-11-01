#include "ft_corewar.h"

t_data	*data(void)
{
	static t_data	d;
	static int		init = 0;

	if (!init && ++init)
		ft_bzero(&d, sizeof(t_data));
	return (&d);
}
