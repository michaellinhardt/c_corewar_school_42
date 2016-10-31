#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

int		ft_accept_fin(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept  fin");
			return (-1);
		}
		if (pile->prev->value != CPL_INST && pile->prev->value != POSITION_INST)
		{
			ft_parse_error(parser, pile->prev->value, pile->prev->tree->token);
			return (-1);
		}
		if (pile->prev->value == HEADER)
		{
			ft_parse_error(parser, pile->prev->value, pile->prev->tree->token);
			return (-1);
		}
		pile->prev->value = CODE_FIN;
		free(pile->tree);
		ft_free_elem_pile(pile, parser);
		return (1);
	}
	return (0);
}

int		ft_accept_code_fin(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CODE_FIN || pile->value == CODE_FIN)
	{
		if (!pile->prev)
			return (ft_parse_error(parser, 0, parser->focus));
		if (pile->prev->value != HEADER && pile->prev->value != CPL_INST &&
				pile->prev->value != POSITION_INST)
			return (ft_parse_error(parser, 0, parser->focus));
		ft_fusion_fils(pile->prev->tree, pile->tree);
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		ft_add_leaf(pile->tree, pile->prev->tree);
		pile->prev->tree = pile->tree;
		pile->prev->value = CODE_FIN;
		ft_free_elem_pile(pile, parser);
		if (parser->debut_pile == parser->end_pile)
			return (CODE_ACCEPT);
		return (1);
	}
	return (0);
}

