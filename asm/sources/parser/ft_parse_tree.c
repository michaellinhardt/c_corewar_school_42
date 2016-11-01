#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

void			ft_add_leaf(t_parse_tree *tree, t_parse_tree *leaf)
{
	tree->fils = (t_parse_tree **)realloc(tree->fils,
			sizeof(t_parse_tree *) * ++tree->nbr_fils);
	tree->fils[tree->nbr_fils - 1] = leaf;
}

t_parse_tree	*ft_create_leaf(t_token *token)
{
	t_parse_tree *leaf;

	leaf = (t_parse_tree *)ft_memalloc(sizeof(t_parse_tree));
	leaf->token = token;
	return (leaf);
}

void			ft_display_parse_tree(t_parse_tree *tree)
{
	int i;

	i = 0;
	if (tree)
	{
		if (tree->token)
		{
			ft_display_type_token(tree->token->token);
			ft_putchar(' ');
			if (tree->token->value)
				ft_putendl(tree->token->value);
			else
				ft_putendl("(NULL)");
		}
		while (i < tree->nbr_fils)
		{
			ft_display_parse_tree(tree->fils[i++]);
		}
	}
}
