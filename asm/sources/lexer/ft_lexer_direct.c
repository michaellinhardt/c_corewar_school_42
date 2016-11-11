/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_direct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:37 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:37 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_direct(t_lexer *lexer, t_token *token)
{
	int i;

	if (*(lexer->focus) == DIRECT_CHAR)
	{
		i = 1;
		if (*(lexer->focus + 1) == '-')
			++i;
		while (i < lexer->size_line && ft_isdigit(*(lexer->focus + i)))
			++i;
		if (i == 1 || (*(lexer->focus + 1) == '-' && i == 2))
			return (0);
		ft_get_value(lexer, token, i);
		lexer->focus += i;
		token->token = DIRECT;
		lexer->size_line -= i;
		return (1);
	}
	return (0);
}
