#include "ft_asm.h"
#include "libft.h"

static int	ft_check_type_arg(t_token *token , int nbr_arg, t_instructions inst)
{
	if (nbr_arg == 4)
		return (0);
	if (token->token == REGISTER)
	{
		if ((inst.types[nbr_arg] & T_REG) == T_REG)
			return (1);
	}
	else if (token->token == DIRECT_LABEL || token->token == DIRECT)
	{
		if ((inst.types[nbr_arg] & T_DIR) == T_DIR)
			return (1);

	}
	else if (token->token == INDIRECT_LABEL || token->token == INDIRECT)
	{
		if ((inst.types[nbr_arg] & T_IND) == T_IND)
			return (1);
	}
	ft_putendl("erreur verrif types arguments");
	return (0);
}

static int 	ft_verif_args(t_parse_tree *args, t_instructions inst, 
		int *nbr)
{

	if (args)
	{	
		int i;

		i = args->nbr_fils - 1;

		if (args->token->value)
		{
			if (!ft_check_type_arg(args->token, *nbr, inst))
				return (0);
			*nbr += 1;
			ft_putendl(args->token->value);
		}
		while (i >= 0)
		{
			ft_verif_args(args->fils[i], inst, nbr);
			--i;
		}
	}
	return (1);
}

int			ft_verif_instruction(t_pile_tree *pile, t_pile_tree *next,
		t_instructions *inst)
{
	int i;
	int j;

	j = 0;
	if (!(i = ft_check_name_instructions(pile->tree->token->value, inst)))
	{
		ft_putendl("Wrong instruction");
		return (0);
	}
	ft_putendl("^^^^^^^^^^^^^^^^^^^^^^^^");
	if (!ft_verif_args(next->tree, *(inst + i), &j))
		return (0);
	if (j != (*(inst + i)).nbr_args)
	{
		ft_putendl("chai pas");
		return (0);
	}
	return (1);
}
