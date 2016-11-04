#include "libft.h"
#include "ft_asm.h"

int		ft_shift_end(t_parser *parser)
{
	if (parser->focus->token == END)
	{
		if (parser->focus_pile)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}
