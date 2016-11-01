#include "libft.h"
#include "ft_asm.h"

static int	ft_check_separator_char(t_parser *parser, t_parse_tree *tree)
{
	if (tree->token->token == SEPARATOR)
	{
		ft_putendl("reduce separator char");
		if (tree->nbr_fils)
		{
			ft_parse_error(parser, SEPARATOR, parser->focus);
			return (-1);
		}
		else
			return (1);
	}
	return (0);
}

int			ft_rule_separator_char(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_separator_char(parser, pile->tree);
	if (ret)
	{
		if (!pile->prev || pile->prev->value != ARG)
		{
			ft_putendl("erreur reduce SEPARATOR char");
			ft_parse_error(parser, SEPARATOR, parser->focus);
			return (-1);
		}
		ft_add_leaf(pile->tree, pile->prev->tree);
		ft_free_elem_pile(pile->prev, parser);
		pile->value = VIRGULE;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (0);
}
