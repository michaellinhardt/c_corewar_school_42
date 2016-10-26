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
				if (ret > 0)
					return (ret);
				if (ret == -1)
					return (ERREUR);
			}
		}
		pile = pile->next;
	}
	//a  ajouter dans une fonction
	// normalement c'est uselless
	/*
	if  (!parser->memory.header && parser->memory.ccomment
			&& parser->memory.name)
		return (ACCEPT);
		*/
	return (1);
}
