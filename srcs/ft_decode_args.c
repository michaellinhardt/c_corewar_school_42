#include "ft_corewar.h"

void	ft_decode_args(char oc_p, t_argument *args)
{	
	args[0].type = (oc_p >> 6) & 0x3;	
	args[1].type = (oc_p >> 4) & 0x3;	
	args[2].type = (oc_p >> 2) & 0x3;	
	args[3].type = oc_p & 0x3;	
}
