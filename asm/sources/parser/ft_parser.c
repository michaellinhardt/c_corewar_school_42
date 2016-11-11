/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:47 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:47 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

static int	ft_parse_code(t_parser *parser)
{
	int action;

	action = 1;
	while (1)
	{
		if (action == SHIFT)
			action = ft_parser_shift(parser);
		else if (action == REDUCE)
			action = ft_parser_reduce(parser);
		else if (action == ACCEPT)
			action = ft_parser_accept(parser);
		else if (action == CODE_ACCEPT)
			break ;
		else
			return (0);
	}
	return (1);
}

int			ft_parser(t_token *token, t_parser *parser)
{
	parser->focus = token;
	return (ft_parse_code(parser));
}
