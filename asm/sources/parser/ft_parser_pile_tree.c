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
		parser->end_pile = parser->debut_pile;
	}
	else
	{
		parser->focus_pile = ft_new_pile_tree();
		parser->end_pile->next = parser->focus_pile;
		parser->focus_pile->prev = parser->end_pile;
	}
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

#include <stdlib.h>
void	ft_free_elem_pile(t_pile_tree *pile, t_parser *parser)
{

	if (pile->prev)
		pile->prev->next = pile->next;
	if (pile->next)
		pile->next->prev = pile->prev;
	if (pile ==  parser->debut_pile)
		parser->debut_pile = pile->next;
	if (pile == parser->end_pile)
		parser->end_pile = parser->end_pile->prev;
	pile->prev = 0;
	pile->next = 0;
	free(pile);
}

void	ft_add_parent_tree(t_pile_tree *pile, t_parser *parser)
{
	if (pile->prev)
	{
		ft_add_leaf(pile->tree, pile->prev->tree);
		ft_free_elem_pile(pile->prev, parser);
	}
}