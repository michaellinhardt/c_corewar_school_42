#include "libft.h"
#include "ft_asm.h"

int				ft_get_type(t_parse_tree *fils)
{
	if (fils->token->token == REGISTER)
		return (1);
	else if (fils->token->token == DIRECT
			|| fils->token->token == DIRECT_LABEL)
		return (2);
	else if (fils->token->token == INDIRECT
			|| fils->token->token == INDIRECT_LABEL)
		return (3);
	return (0);
}

unsigned char	ft_set_oc_p(unsigned int id, t_parse_tree *inst)
{
	int				i;
	int				decalage;
	unsigned char	oc_p;

	oc_p = 0;
	i = 0;
	decalage = 6;
	(void)id;
	while (i < inst->nbr_fils)
	{
		oc_p |= ft_get_type(inst->fils[i]) << decalage;
		decalage -= 2;
		++i;
	}
	return (oc_p);
}
