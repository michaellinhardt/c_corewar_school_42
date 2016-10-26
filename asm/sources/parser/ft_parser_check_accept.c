#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

/*
** faire tableau de pointeurs sur fonctiosn comme shift et reduce
*/

int	ft_accept_header(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == MINI_NAME || pile->value == MINI_COMMENT)
	{
	/*
	t_parse_tree *tree;

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
	*/
	}
	return (0);
}

int	ft_accept_label(t_parser *parser, t_pile_tree *pile)
{

	return (0);
}

int	ft_accept_name(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == MINI_NAME)
	{
		if (!pile->next && pile->next->value != ENDLINE)
		{
			ft_putendl("erreur mini name");
			return (-1);
		}
		ft_putendl("accept mini name");
		ft_add_leaf(pile->next->tree, pile->tree);
		ft_free_elem_pile(pile, parser);
		return (SHIFT);
	}
	return (0);
}

int	ft_accept_comment(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == MINI_COMMENT)
	{
		if (!pile->next && pile->next->value != ENDLINE)
		{
			ft_putendl("erreur mini comment");
			return (-1);
		}
		ft_putendl("accept mini comment");
		return (SHIFT);
	// add parent + free elem pile
	}
	return (0);
}
int	ft_accept_argument(t_parser *parser, t_pile_tree *pile)
{
	return (0);
}

int	ft_accept_instruction(t_parser *parser, t_pile_tree *pile)
{
	return (0);
}
