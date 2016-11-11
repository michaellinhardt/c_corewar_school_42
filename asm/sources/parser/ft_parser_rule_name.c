/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_rule_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:50 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

static int	ft_check_rule_name(t_parse_tree *tree, t_parser *parser)
{
	if (tree && tree->token->token == COMMAND_NAME)
	{
		if (tree->nbr_fils != 1)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		if (tree->fils[0]->token->token != STRING)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		else if (tree->fils[0]->token->size > PROG_NAME_LENGTH + 2)
		{
			ft_parse_error(parser, MINI_NAME, tree->fils[0]->token);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int			ft_rule_name(t_parser *parser, t_pile_tree *pile)
{
	int ret;

	ret = ft_check_rule_name(pile->tree, parser);
	if (ret == 1)
	{
		pile->value = MINI_NAME;
		parser->focus_pile = 0;
		return (SHIFT);
	}
	return (ret);
}
