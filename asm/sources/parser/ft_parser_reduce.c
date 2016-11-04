#include "libft.h"
#include "ft_asm.h"

int		ft_parser_reduce(t_parser *parser)
{
	int			ret;
	int			i;
	t_pile_tree *pile;

	pile = parser->focus_pile;
	while (pile)
	{
		if (pile->tree)
		{
			i = 0;
			while (i < NBR_REDUCE)
			{
				ret = parser->f_reduce[i++](parser, pile);
				if (ret > 0)
					return (ret);
				if (ret == -1)
					return (ERREUR);
			}
		}
		pile = pile->next;
	}
	ft_parse_error(parser, 0, parser->end_pile->tree->token);
	return (-1);
}
