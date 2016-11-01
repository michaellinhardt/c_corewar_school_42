#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

static void	ft_complete_instruction(t_parse_tree *inst, t_parse_tree *args)
{
	int i;

	if (args)
	{
		i = args->nbr_fils - 1;
		if (args->token->value)
			ft_add_leaf(inst, args);
		while (i >= 0)
		{
			ft_complete_instruction(inst, args->fils[i]);
			i--;
		}
	}
}

static int	ft_accept_instruction_error(t_parser *parser, t_pile_tree *pile)
{
	if (pile->tree && pile->tree->fils)
		ft_parse_error(parser, LAST_ARG, pile->tree->fils[0]->token);
	else
		ft_parse_error(parser, LAST_ARG, parser->focus);
	return (-1);
}

static void	ft_accept_instruction_cpl(t_parser *parser, t_pile_tree *pile)
{
	ft_complete_instruction(pile->prev->tree, pile->tree);
	pile->prev->value = CPL_INST;
	ft_free_arguments(pile->tree);
	pile->tree->fils = 0;
	pile->tree->nbr_fils = 0;
	ft_add_leaf(pile->tree, pile->prev->tree);
	pile->prev->tree = pile->tree;
	ft_free_elem_pile(pile, parser);
}

int			ft_accept_instruction(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == LAST_ARG)
	{
		if (!pile->prev)
			return (ft_parse_error(parser, -49, pile->tree->token));
		if (pile->prev->value == VIRGULE)
			return (0);
		if (pile->prev->value == INST)
		{
			if (ft_verif_instruction(pile->prev, pile, parser->inst))
			{
				ft_accept_instruction_cpl(parser, pile);
				return (1);
			}
			else
				return (ft_accept_instruction_error(parser, pile));
		}
		else
			return (ft_parse_error(parser, -49, pile->tree->token));
	}
	return (0);
}

int			ft_accept_instruction_plus(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CPL_INST)
	{
		if (!pile->prev)
			return (ft_parse_error(parser, CPL_INST, pile->tree->token));
		if (pile->prev->value != CPL_INST)
			return (0);
		pile->prev->tree = ft_fusion_fils(pile->prev->tree, pile->tree);
		pile->prev->value = CPL_INST;
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		ft_free_elem_pile(pile, parser);
		return (1);
	}
	return (0);
}
