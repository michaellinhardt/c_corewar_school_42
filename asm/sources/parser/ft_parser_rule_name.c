#include "libft.h"
#include "ft_asm.h"

static int ft_check_rule_name(t_parse_tree *tree)
{
	if (tree && tree->token->token == COMMAND_NAME)
	{
		if (tree->nbr_fils != 1)
		{
			ft_putendl("ERROR RULE NAME");
			return (-1);
		}
		if (tree->fils[0]->token->token != STRING)
		{
			ft_putendl("ERROR RULE NAME");
			return (-1);
		}
		ft_putendl("reduction name + string");
		return (1);
	}
	return (0);
}


int		ft_rule_name(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_rule_name(pile->tree);
	if (ret == 1)
	{
		/*
		pile->value = MINI_NAME;
		if (parser->memory.name)
			return (-1);
		parser->memory.name = 1;
		parser->focus_pile = 0;
		return (SHIFT);
		*/
		pile->value = MINI_NAME;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (ret);
}
