/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:39 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:39 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_whitespace(t_lexer *lexer, t_token *token)
{
	int size;

	size = 0;
	while (ft_isspace(*(lexer->focus + size)) &&
			*(lexer->focus + size) != '\n')
		++size;
	if (size)
	{
		ft_get_value(lexer, token, size);
		token->token = WHITESPACE;
		lexer->focus += size;
		lexer->size_line -= size;
	}
	return (size);
}
