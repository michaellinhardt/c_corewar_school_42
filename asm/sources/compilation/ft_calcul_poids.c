/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_poids.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:30 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:30 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

static int	ft_get_poids_args(t_token *token, t_instructions inst)
{
	if (token->token == REGISTER)
		return (1);
	if (token->token == DIRECT || token->token == DIRECT_LABEL)
	{
		if (inst.flag_size_ind)
			return (2);
		else
			return (4);
	}
	return (2);
}

int			ft_calcul_size_instruction(t_parse_tree *tree, t_instructions *inst,
		unsigned int poids)
{
	int	i;
	int	id;

	tree->position = poids;
	if (tree->token->token == INSTRUCTION)
	{
		id = tree->id_instruction;
		i = 0;
		if (inst[id].flag_ocp)
			tree->poids++;
		tree->poids++;
		while (i < tree->nbr_fils)
		{
			tree->poids += ft_get_poids_args(tree->fils[i]->token, inst[id]);
			tree->fils[i]->position = tree->position;
			++i;
		}
	}
	return (tree->poids);
}

int			ft_calcul_size_label(t_parse_tree *tree, t_instructions *inst,
		unsigned int poids)
{
	int	i;

	tree->position = poids;
	if (tree->token->token == LABEL)
	{
		i = 0;
		while (i < tree->nbr_fils)
		{
			tree->poids += ft_calcul_size_instruction(tree->fils[i], inst,
					tree->position + tree->poids);
			++i;
		}
	}
	return (tree->poids);
}

int			ft_calcul_poids(t_parse_tree *tree, t_instructions *inst,
		unsigned int poids)
{
	int i;

	if (tree)
	{
		i = 0;
		while (i < tree->nbr_fils)
		{
			if (tree->fils[i] && tree->fils[i]->token->token == ENDLINE)
				return (ft_calcul_poids(tree->fils[i], inst, poids));
			else if (tree->fils[i] &&
					tree->fils[i]->token->token == INSTRUCTION)
				poids += (ft_calcul_size_instruction(tree->fils[i],
							inst, poids));
			else if (tree->fils[i] && tree->fils[i]->token->token == LABEL)
				poids += (ft_calcul_size_label(tree->fils[i], inst, poids));
			++i;
		}
	}
	return (poids);
}
