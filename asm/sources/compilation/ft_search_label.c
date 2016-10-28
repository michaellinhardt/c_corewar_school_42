#include "libft.h"
#include "ft_asm.h"

int		ft_get_label(t_parse_tree *root, char *value, int *poids)
{
	unsigned int i;

	if (root)
	{
		i = 0;
		if (root->token->token == LABEL && !ft_strncmp(value,
					root->token->value, ft_strlen(root->token->value) - 1))
		{
			if (!*(value + ft_strlen(root->token->value) - 1))
			{
				ft_putendl(value);
				ft_printf("valeur poids before %d\n", *poids);
				*poids = root->position - *poids;	
				ft_printf("valeur poids %d\n", *poids);
				ft_printf("valeur label %d\n", root->position);
				return (1);
			}
		}
		while (i < root->nbr_fils)
		{
			if (ft_get_label(root->fils[i], value, poids))
				return (1);
			++i;
		}
	}
	return (0);
}

int		ft_search_label(t_parse_tree *root, t_parse_tree *tree)
{
	unsigned int i;

	if (tree)
	{
		i = 0;
		if (tree->token->token == DIRECT_LABEL) 
		{
			if(!ft_get_label(root, tree->token->value + 2, &tree->position))
				return (1);
		}
		else if (tree->token->token == INDIRECT_LABEL) 
		{
			if(!ft_get_label(root, tree->token->value + 1, &tree->position))
				return (1);
		}
		while (i < tree->nbr_fils)
		{
			if (ft_search_label(root, tree->fils[i]))
				return (1);
			++i;
		}
	}
	return (0);
}
