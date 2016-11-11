/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_endline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:38 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:38 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "libft.h"

int		ft_lexer_endline(t_lexer *lexer, t_token *token)
{
	if (*(lexer->focus) == '\n')
	{
		token->token = ENDLINE;
		lexer->size_line = 0;
		lexer->focus = 0;
		return (1);
	}
	return (0);
}
