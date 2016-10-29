#include "ft_asm.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_erreur_parser_instruction(t_token *token, t_instructions inst,
		int erreur)
{
	ft_printf("parse error : ");
	if (erreur == PARSER_ARG_WRONG)
		ft_printf("instruction: %s has an invalid arg %s%s",
				inst.name, RED, token->value);
	else if (erreur == PARSER_INSTRUCTION_WRONG)
		ft_printf("Unknow instruction : %s%s", RED, token->value);
	else if (erreur == PARSER_INSTRUCTION_REGISTRE)
		ft_printf("Invalid size of registre : %s%s", RED, token->value);
	else if (erreur == PARSER_INSTRUCTION_NBR)
		ft_printf("Invalid number of args : %s%s", RED, inst.name);
	ft_putstr(NEUTRE);
	ft_putstr(" at : ");
	ft_printf("[%d:", token->y);
	ft_printf("%d]", token->x + 1);
	ft_putchar('\n');
	exit(1);
}

static int	ft_check_type_arg(t_token *token , int nbr_arg, t_instructions inst)
{
	int nbr;

	if (nbr_arg == 4)
		return (0);
	if (token->token == REGISTER)
	{
		if ((inst.types[nbr_arg] & T_REG) == T_REG)
		{
			nbr = ft_atoi(token->value + 1);
			if (nbr >= 1 && nbr <= 16)
				return (1);
			else
			ft_erreur_parser_instruction(token, inst, PARSER_INSTRUCTION_REGISTRE);
		}
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
		ft_erreur_parser_instruction(token, 
				inst, PARSER_INSTRUCTION_NBR);
//	ft_putendl("erreur verrif types arguments");
	return (0);
}

static int 	ft_verif_args(t_parse_tree *args, t_instructions inst, 
		int *nbr)
{
	int i;

	if (args)
	{	
		i = args->nbr_fils - 1;
		if (args->token->value)
		{
			if (!ft_check_type_arg(args->token, *nbr, inst))
				return (0);
			*nbr += 1;
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
		ft_erreur_parser_instruction(pile->tree->token, 
				inst[pile->tree->id_instruction], PARSER_INSTRUCTION_WRONG);
		return (0);
	}
	if (!ft_verif_args(next->tree, *(inst + i), &j))
		return (0);
	if (j != (*(inst + i)).nbr_args)
	{
		ft_erreur_parser_instruction(pile->tree->token, 
				inst[pile->tree->id_instruction], PARSER_INSTRUCTION_NBR);
		return (0);
	}
	pile->tree->id_instruction = i;
	return (1);
}
