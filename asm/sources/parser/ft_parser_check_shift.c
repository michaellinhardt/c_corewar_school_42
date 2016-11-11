/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_shift.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:49 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:49 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

int		ft_shift_end(t_parser *parser)
{
	if (parser->focus->token == END)
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
