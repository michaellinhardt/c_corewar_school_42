#include "libft.h"
#include "ft_asm.h"
#include <stdlib.h>

static int	ft_check_header(t_pile_tree *pile, t_parser *parser)
{
	t_parse_tree *tree;

	ft_printf("valeur %d\n", parser->memory.header);
	if (!(parser->memory.header) && (parser->memory.ccomment) &&
			parser->memory.name)
	{
		ft_putendl("mouhahahahhaha");

		if (pile->value == CMD_NAME)
		{
			ft_putendl("reduction header");
			if (!pile->next || pile->next->value != CMD_COMMENT)
				return (-1);
			ft_add_leaf(pile->tree, pile->next->tree->fils[0]);
			tree = pile->next->tree;
			pile->next->tree = pile->next->tree->fils[0];
			free (tree);
			ft_free_elem_pile(pile->next, parser);
			return (1);
		}
		else if (pile->value == CMD_COMMENT)
		{
			if (!pile->next || pile->next->value != CMD_NAME)
				return (-1);
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
				return (1);
			}
		begin = begin->next;
	}
	return (1);
}
