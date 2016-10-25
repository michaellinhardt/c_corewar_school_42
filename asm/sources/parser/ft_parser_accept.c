#include "libft.h"
#include "ft_asm.h"
#include <stdlib.h>


/*
** faire tableau de pointeurs sur fonctiosn comme shift et reduce
*/
static int	ft_check_header(t_pile_tree *pile, t_parser *parser)
{
	t_parse_tree *tree;

	if (!(parser->memory.header) && (parser->memory.ccomment) &&
			parser->memory.name)
	{
		ft_putendl("reduction  header");
		if (pile->value == CMD_NAME)
		{
			if (!pile->next || pile->next->value != CMD_COMMENT)
				return (-1);
			ft_add_leaf(pile->tree, pile->next->tree->fils[0]);
			tree = pile->next->tree;
			pile->next->tree = pile->next->tree->fils[0];
			free (tree->fils);
			free (tree);
			ft_free_elem_pile(pile->next, parser);
			return (1);
		}
		else if (pile->value == CMD_COMMENT)
		{
			if (!pile->next || pile->next->value != CMD_NAME)
				return (-1);
			ft_add_leaf(pile->next->tree, pile->tree->fils[0]);
			tree = pile->tree;
			pile->tree = pile->tree->fils[0];
			free (tree->fils);
			free (tree);
			ft_free_elem_pile(pile, parser);
			return (1);
		}
	}
	return (0);
}


int		ft_parser_accept(t_parser *parser)
{
	t_pile_tree *begin;

	begin = parser->debut_pile;
	while (begin)
	{
			if (ft_check_header(begin, parser))
			{
				parser->memory.header = 1;
				begin->value = HEADER;
				parser->focus_pile = 0;
				return (SHIFT);
			}
			// il faut check pour virgules et tout le bordel
			if (ft_check_separator_char(begin , parser))
			{
				// la regle n'est pas finis 
				return (ACCEPT);
			}
			// apres faut checker pour les '\n'
			//


			// pour finir on check pour linstruction
			//
			//

			// en en epilogue on check pour le LABEL
			// ca fait une sorte de lecture de droite a gauche de nos regles
		begin = begin->next;
	}
	return (SHIFT);
}
