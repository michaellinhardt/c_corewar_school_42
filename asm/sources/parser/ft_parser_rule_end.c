#include "libft.h"
#include "ft_asm.h"

static int	ft_check_end(t_pile_tree *pile, t_parse_tree *tree, t_parser *parser)
{
	if (tree->token->token == END)
	{
		pile->value = FIN;
		ft_putendl("reduction end");
//		ft_add_parent_tree(pile, parser);
		return (1);
	}
	return (0);
}

int		ft_rule_end(t_parser *parser, t_pile_tree *pile)
{
	if (ft_check_end(pile, pile->tree, parser))
	{
		parser->focus_pile = 0;
		return (ACCEPT);
	}
	return (0);
}
