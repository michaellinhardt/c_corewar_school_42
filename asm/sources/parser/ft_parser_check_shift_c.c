/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_shift_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:49 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:49 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		ft_shift_separator_char(t_parser *parser)
{
	if (parser->focus->token == SEPARATOR)
	{
		if (parser->focus_pile)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_direct_label(t_parser *parser)
{
	if (parser->focus->token == DIRECT_LABEL)
	{
		if (parser->focus_pile)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_direct(t_parser *parser)
{
	if (parser->focus->token == DIRECT)
	{
		if (parser->focus_pile)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_indirect(t_parser *parser)
{
	if (parser->focus->token == INDIRECT)
	{
		if (parser->focus_pile)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_indirect_label(t_parser *parser)
{
	if (parser->focus->token == INDIRECT_LABEL)
	{
		if (parser->focus_pile)
		{
			ft_parse_error(parser, 0, parser->focus);
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}
