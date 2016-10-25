#include "libft.h"
#include "ft_asm.h"

static int	ft_check_instruction(t_parse_tree *tree, t_instructions *inst)
{
	if (tree->token->token == INSTRUCTION)
	{
		ft_putendl("reduce rule instruction");
		if (!ft_check_name_instructions(tree->token->value, inst))
		{
			ft_putendl("error inst");
			return (0);
		}
		else
			return (SHIFT);
	}
	return (0);
}

int		ft_rule_instruction(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_instruction(pile->tree, parser->inst);
	if (ret == 1)
	{
		pile->value = INST;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (ret);
}
