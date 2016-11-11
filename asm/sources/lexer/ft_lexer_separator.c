/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:39 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:39 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		ft_lexer_separator(t_lexer *lexer, t_token *token)
{
	if (*(lexer->focus) == SEPARATOR_CHAR)
	{
		token->token = SEPARATOR;
		token->size = 1;
		lexer->size_line--;
		lexer->focus++;
		return (1);
	}
	return (0);
}
