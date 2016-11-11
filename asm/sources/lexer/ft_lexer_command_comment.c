/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_command_comment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:36 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:36 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "ft_asm.h"
#include "libft.h"

int		ft_lexer_command_comment(t_lexer *lexer, t_token *token)
{
	if (*(lexer->line) != '.')
		return (0);
	if (lexer->size_line > 7 &&
			!ft_strncmp(COMMENT_CMD_STRING, lexer->focus, 8))
	{
		ft_get_value(lexer, token, 8);
		lexer->focus += 8;
		token->token = COMMAND_COMMENT;
		lexer->size_line -= 8;
		return (1);
	}
	return (0);
}
