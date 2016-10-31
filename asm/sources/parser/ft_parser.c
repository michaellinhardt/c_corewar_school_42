#include "libft.h"
#include "ft_asm.h"

// on parse d'abord l'header

#include <stdlib.h>
static int	ft_parse_code(t_parser *parser)
{
	int action;

	action = 1;
	while (1)
	{

		if (action == SHIFT)
		{
			action = ft_parser_shift(parser);
		}
		else if (action == REDUCE)
		{
			action = ft_parser_reduce(parser);
		}
		else if (action == ACCEPT)
		{

			action = ft_parser_accept(parser);
				// accept
		}
		else if (action == CODE_ACCEPT)
		{
			ft_putendl("fin parser");
			break;
		}
		else
		{
			return (0);
			ft_putendl("while error parser");
			ft_parse_error(parser, 0, 0);
			break ;
		}

	}
	if (!parser->end_pile)
		ft_printf("y a un soucis\n");
	ft_putendl("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	t_pile_tree *pile;
	pile = parser->debut_pile;
	while (pile)
	{
		if (pile->tree)
		{
		//	ft_printf("value : %d\n", pile->value);
			ft_display_parse_tree(pile->tree);
		}
		ft_putendl("----------------");
		pile = pile->next;
	}
//	exit(1);

	return (1);
}

int		ft_parser(t_token *token, t_parser *parser)
{
	(void)token;
	(void)parser;

	parser->focus = token; // shift
	ft_putendl("debut parser");

	return (ft_parse_code(parser));
}
