#include "libft.h"
#include "ft_asm.h"

static int ft_check_rule_name(t_parse_tree *tree)
{
	if (tree && tree->token->token == COMMAND_NAME)
	{
		if (tree->nbr_fils != 1)
			return (0);
		if (tree->fils[0]->token->token != STRING)
			return (0);
		ft_putendl("reduction name + string");
		return (1);
	}
	return (0);
}

static int	ft_check_endline(t_pile_tree *pile, t_parse_tree *tree, t_parser *parser)
{
	if (tree->token->token == ENDLINE)
	{
		ft_putendl("reduction end");
		ft_add_parent_tree(pile, parser);
		return (1);
	}
	return (0);
}

int		ft_parser_reduce(t_parser *parser)
{
	t_pile_tree *pile;

	pile = parser->focus_pile;

	while (pile)
	{
		if (pile->tree)
		{
			if (ft_check_rule_name(pile->tree))
			{
				parser->focus_pile = 0;
				return (1);
			}
			if (ft_check_endline(pile, pile->tree, parser))
			{
				parser->focus_pile = 0;
				return (1);
			}
		}
		ft_display_parse_tree(pile->tree);
		ft_putendl("----------------");
		pile = pile->next;
	}
	// on checck la pile pour monter l'arbre
	pile = parser->debut_pile;
	while (pile)
	{
		pile = pile->next;
	}
	ft_putendl("!!!!!!!!!!!!!!!!!!!!!!!!");
	return (1);
}
