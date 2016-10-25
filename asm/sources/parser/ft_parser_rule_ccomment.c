#include "libft.h"
#include "ft_asm.h"

static	int	ft_check_rule_ccomment(t_parse_tree *tree)
{
	if (tree && tree->token->token == COMMAND_COMMENT)
	{
		if (tree->nbr_fils != 1)
		{
			ft_putendl("ERROR");
			return (-1);
		}
		if (tree->fils[0]->token->token != STRING)
		{
			ft_putendl("ERROR");
			return (-1);
		}
		ft_putendl("reduction command comment + string");
		return (1);
	}
	return (0);
}

int		ft_rule_ccomment(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_rule_ccomment(pile->tree);
	if (ret == 1)
	{
		pile->value = MINI_COMMENT;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (ret);
}
