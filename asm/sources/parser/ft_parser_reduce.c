#include "libft.h"
#include "ft_asm.h"




int		ft_parser_reduce(t_parser *parser)
{
	int		ret;
	int		i;
	t_pile_tree *pile;

	pile = parser->focus_pile;
	while (pile)
	{
		if (pile->tree)
		{
			i = 0;
			while ( i < NBR_REDUCE)
			{
				ret = parser->f_reduce[i++](parser, pile);
				if (ret == 1)
					break;
				if (ret == -1)
					return (ERREUR);
			}
			/*
			if (ft_check_rule_name(pile->tree))
			{
				pile->value = MINI_NAME;
				if (parser->memory.name)
					return (0);
				parser->memory.name = 1;
				parser->focus_pile = 0;
				return (1);
			}
			if (ft_check_rule_ccomment(pile->tree))
			{
				pile->value = MINI_COMMENT;
				if (parser->memory.ccomment)
					return (0);
				parser->memory.ccomment = 1;
				parser->focus_pile = 0;
				return (SHIFT);
			}
			if (ft_check_endline(pile, pile->tree, parser))
			{
				parser->focus_pile = 0;
				return (SHIFT);
			}
			if (ft_check_instruction(pile->tree, parser->inst))
			{
				parser->focus_pile = 0;
				return (SHIFT);
			}
			*/
		}
		pile = pile->next;
	}
	//a  ajouter dans une fonction
	if  (!parser->memory.header && parser->memory.ccomment
			&& parser->memory.name)
	{
		ft_putendl("mouhkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkahahahhaha");
		return (3);
	}
	return (1);
}
