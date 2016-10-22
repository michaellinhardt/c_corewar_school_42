#include "libft.h"
#include "ft_asm.h"

t_pile_tree		*ft_new_pile_tree(void)
{
	t_pile_tree *new;

	new = (t_pile_tree *)ft_memalloc(sizeof(t_pile_tree));
	return (new);
}

void		ft_create_new_pile_tree(t_parser *parser)
{
	if (!parser->debut_pile)
	{
		parser->debut_pile = ft_new_pile_tree();
		parser->focus_pile = parser->debut_pile;
	}
	else
		parser->focus_pile = ft_new_pile_tree();
}

/*
** creer un nouveau node ou ajoutes des leafs au noeaud exisatn
*/
void		ft_add_tree_shift(t_parser *parser)
{
	t_parse_tree *leaf;

	leaf = ft_create_leaf(parser->focus);
	if (!parser->focus_pile)
	{
		ft_create_new_pile_tree(parser);
		parser->focus_pile->tree = leaf;
	}
	else
		ft_add_leaf(parser->focus_pile->tree, leaf);
}
