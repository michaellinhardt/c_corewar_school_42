#include "libft.h"
#include "ft_asm.h"

static int	ft_check_end(t_pile_tree *pile, t_parse_tree *tree)
{
	if (tree->token->token == END)
	{
		pile->value = FIN;
		return (1);
	}
	return (0);
}

int			ft_rule_end(t_parser *parser, t_pile_tree *pile)
{
	if (ft_check_end(pile, pile->tree))
	{
		parser->focus_pile = 0;
		return (ACCEPT);
	}
	return (0);
}
