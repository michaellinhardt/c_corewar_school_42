#include "ft_corewar.h"

void	ft_decode_args(char oc_p, t_argument *args)
{
	ft_bzero(&args->type, 4);
	//(oc_p) = (oc_p >> 4) | (oc_p << 4);
	args[0].type = (oc_p >> 6) & 0x3;	
	args[1].type = (oc_p >> 4) & 0x3;	
	args[2].type = (oc_p >> 2) & 0x3;	
	args[3].type = oc_p & 0x3;	
}

void	ft_no_ocp(t_argument *args, t_arg_type *types)
{
	args[0].type = types[0];
	args[1].type = types[1];
	args[2].type = types[2];
	args[3].type = types[3];
}
