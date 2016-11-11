/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:31 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:31 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

int		ft_get_label(t_parse_tree *root, char *value, int *poids)
{
	int i;

	if (root)
	{
		if (root->token->token == LABEL && !ft_strncmp(value,
					root->token->value, ft_strlen(root->token->value) - 1))
		{
			if (!*(value + ft_strlen(root->token->value) - 1))
			{
				*poids = root->position - *poids;
				return (1);
			}
		}
		i = -1;
		while (++i < root->nbr_fils)
		{
			if (ft_get_label(root->fils[i], value, poids))
				return (1);
		}
	}
	return (0);
}

int		ft_search_label(t_parse_tree *root, t_parse_tree *tree)
{
	int i;

	if (tree)
	{
		i = 0;
		if (tree->token->token == DIRECT_LABEL)
		{
			if (!ft_get_label(root, tree->token->value + 2, &tree->position))
				return (1);
		}
		else if (tree->token->token == INDIRECT_LABEL)
		{
			if (!ft_get_label(root, tree->token->value + 1, &tree->position))
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
