/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_accept.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:47 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:47 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

int		ft_parser_accept(t_parser *parser)
{
	int			ret;
	int			i;
	t_pile_tree *end;

	end = parser->end_pile;
	while (end)
	{
		i = 0;
		while (i < NBR_ACCEPT)
		{
			ret = parser->f_accept[i](parser, end);
			if (ret == 1)
			{
				end = parser->end_pile;
				continue ;
			}
			else if (ret == -1)
				return (0);
			else if (ret == CODE_ACCEPT)
				return (CODE_ACCEPT);
			++i;
		}
		end = end->prev;
	}
	return (SHIFT);
}
