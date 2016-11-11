/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_rule_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:50 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "libft.h"

static int	ft_check_label(t_parse_tree *tree)
{
	if (tree->token->token == LABEL)
		return (1);
	return (0);
}

int			ft_rule_label(t_parser *parser, t_pile_tree *pile)
{
	if (ft_check_label(pile->tree))
	{
		pile->value = POSITION;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (0);
}
