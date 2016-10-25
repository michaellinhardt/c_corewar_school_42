#include "libft.h"
#include "ft_asm.h"

// on parse d'abord l'header

static int	ft_parse_code(t_parser *parser)
{
	int action;
	static int test = 0;

	(void)parser;
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
		else
		{
			ft_printf("error\n");
			//print error
			break ;
			return (0);
		}

		++test;
		if (test == 13)
			break;
	}


	ft_putendl("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	t_pile_tree *pile;

	pile = parser->debut_pile;

	while (pile)
	{
		if (pile->tree)
		{
			ft_display_parse_tree(pile->tree);
		}
		ft_putendl("----------------");
		pile = pile->next;
	}

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
