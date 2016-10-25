#include "ft_asm.h"

#include "libft.h"
// on ignore les espaces;
int		ft_parser_shift(t_parser *parser)
{
	// on ajoute des noeuds
	if (!parser->focus)
		return (0);
	if (parser->focus->token == WHITESPACE)
	{
		parser->focus = parser->focus->next;
		return (1);
	}
	else if (parser->focus->token == COMMAND_NAME)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (1);
	}
	else if (parser->focus->token == STRING)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (2);
	}
	else if (parser->focus->token == ENDLINE)
	{
		/*
		** Ignorer les '\n' au debut et les '\n' multiples
		*/

		if (!parser->debut_pile || (parser->end_pile->tree && 
					parser->end_pile->tree->token->token == ENDLINE))
		{
			parser->focus = parser->focus->next;
			return (1);

		}
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (2);
	}
	else if (parser->focus->token == COMMAND_COMMENT)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (1);
	}
	return (2);
}
