#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

void		ft_free_pointeur_tab_fils(t_parse_tree *tree)
{
	int i;

	i = 0;
	if (tree)
	{
		while (i < tree->nbr_fils)
		{
			ft_free_pointeur_tab_fils(tree->fils[i]);
			++i;
		}
		if (tree->fils)
		{
			free(tree->fils);
			tree->fils = 0;
		}
		if (!tree->token->value)
		{
			free(tree);
			tree = 0;
		}
	}
}

void	ft_free_arguments(t_parse_tree *tree)
{
	int i;

	i = 0;
	if (tree)
	{
		while (i < tree->nbr_fils)
		{
			ft_free_arguments(tree->fils[i]);
			++i;
		}
		if (tree->fils)
		{
			free(tree->fils);
			tree->fils = 0;
		}
		if (!tree->token->value)
		{
			if (tree->token->token != ENDLINE)
			{
			free(tree);
			tree = 0;
			}
		}
	}
}
