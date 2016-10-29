#include "libft.h"
#include "ft_asm.h"

static int	ft_check_separator_char(t_parse_tree *tree)
{
	if (tree->token->token == SEPARATOR)
	{
		ft_putendl("reduce separator char");
		if (tree->nbr_fils)
		{
			ft_putendl("erreur check separator char");
			return (-1);
		}
		else
			return (1);
	}
	return (0);
}

int		ft_rule_separator_char(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_separator_char(pile->tree);
	if (ret)
	{
		if (!pile->prev || pile->prev->value != ARG)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			ft_putendl("erreur reduce SEPARATOR char");
			return (-1);
		}
		ft_add_leaf(pile->tree, pile->prev->tree);
		ft_free_elem_pile(pile->prev, parser);
		//ft_add_parent_tree(pile, parser);
		pile->value = VIRGULE;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (0);
}
