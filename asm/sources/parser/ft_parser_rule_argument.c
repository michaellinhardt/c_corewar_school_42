#include "ft_asm.h"
#include "libft.h"

int		ft_check_argument(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == ARG)
	{
		ft_putendl("reduce argument");
		if (pile->tree->nbr_fils)
		{
			ft_parse_error(parser, 0, parser->focus);	
			return (-1);
		}
		return (1);
	}
	return (0);
}

int		ft_rule_argument(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_argument(parser, pile);
	if (ret == 1)
	{
		parser->focus_pile->value = ARG;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	if (ret == -1)
	{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
	}
	return (0);
}
