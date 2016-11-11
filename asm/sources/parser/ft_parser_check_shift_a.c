/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_shift_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:49 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:49 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		ft_shift_no_focus(t_parser *parser)
{
	if (!parser->focus)
		return (-1);
	return (0);
}

int		ft_shift_whitespaces(t_parser *parser)
{
	if (parser->focus->token == WHITESPACE)
	{
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_comment(t_parser *parser)
{
	if (parser->focus->token == COMMENT)
	{
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_command_name(t_parser *parser)
{
	if (parser->focus->token == COMMAND_NAME)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_string(t_parser *parser)
{
	if (parser->focus->token == STRING)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}
