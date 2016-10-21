#include "ft_asm.h"

int		ft_parser_shift(t_parser *parser)
{
	// on deplace le focus
	if (!(parser->focus))
		return (0);
	if (!(parser->focus = parser->focus->next))
		return (0);

	if (parser->focus->token == WHITESPACE)
	{
		parser->focus = parser->focus->next;
		ft_parser_shift(parser);
	}
	if (!parser->focus_pile)
	{

	}

	return (2);
}
