/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_rule_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:50 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

static int	ft_check_instruction(t_parse_tree *tree)
{
	if (tree->token->token == INSTRUCTION)
	{
		return (SHIFT);
	}
	return (0);
}

int			ft_rule_instruction(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_instruction(pile->tree);
	if (ret == 1)
	{
		pile->value = INST;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (ret);
}
