#include "ft_asm.h"

int		ft_parser_shift(t_parser *parser)
{
	int token;

	if (!parser->focus)
		return (PRETRE);
	parser->focus = parser->focus->next;
	token = parser->focus->token ;
	if (parser->focus->token == 
	return (SHIFT);
	return (REDUCE);
	return (PRETRE);
}
