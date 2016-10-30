#include "libft.h"
#include "ft_asm.h"

static int	ft_check_endline(t_pile_tree *pile, t_parse_tree *tree,
		t_parser *parser)
{
	if (tree->token->token == ENDLINE)
	{
		pile->value = FIN_LINE;
		ft_putendl("reduction endline");
		return (1);
	}
	return (0);
}

int		ft_rule_endline(t_parser *parser, t_pile_tree *pile)
{
	if (ft_check_endline(pile, pile->tree, parser))
	{
		parser->focus_pile = 0;
		return (ACCEPT);
	}
	return (0);
}
