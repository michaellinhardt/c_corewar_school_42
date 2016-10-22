#include "libft.h"
#include "ft_asm.h"

static int ft_check_rule_name(t_parse_tree *tree)
{
	if (tree && tree->token->token == COMMAND_NAME && tree->nbr_fils == 1)
	{
		ft_putendl("reduction name + string");
		return (1);
	}
	return (0);
}

static int	ft_check_endline(t_parse_tree *tree)
{


	return (0);
}

int		ft_parser_reduce(t_parser *parser)
{
	t_pile_tree *pile;

	pile = parser->focus_pile;
	// on check les focus pour voir si y a une reduction
	while (pile)
	{
		if (ft_check_rule_name(pile->tree))
		{
			parser->focus_pile = 0;
			return (1);
		}
		if (ft_check_endline(pile->tree))
		{

			return (1);
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
