/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_shift_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:49 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:49 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		ft_shift_endline(t_parser *parser)
{
	if (parser->focus->token == ENDLINE)
	{
		if (!parser->debut_pile || (parser->end_pile->tree &&
					parser->end_pile->tree->token->token == ENDLINE))
		{
			parser->focus = parser->focus->next;
			return (SHIFT);
		}
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_command_comment(t_parser *parser)
{
	if (parser->focus->token == COMMAND_COMMENT)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_label(t_parser *parser)
{
	if (parser->focus->token == LABEL)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_instruction(t_parser *parser)
{
	if (parser->focus->token == INSTRUCTION)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_register(t_parser *parser)
{
	if (parser->focus->token == REGISTER)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		parser->focus_pile->value = ARG;
		return (REDUCE);
	}
	return (0);
}
