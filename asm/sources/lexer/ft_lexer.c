/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:41:59 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:20:05 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		ft_get_free_line(t_lexer *lexer)
{
	if (lexer->line)
	{
		free(lexer->line);
		lexer->line = 0;
	}
	if (!(lexer->line = ft_get_line(lexer->fd, lexer)))
		return (1);
	lexer->focus = lexer->line;
	lexer->x = 0;
	return (0);
}

int		ft_lexer(t_lexer *lexer, int i, int ret)
{
	t_token *token;

	while (1)
	{
		i = 0;
		if (!lexer->size_line)
			if (ft_get_free_line(lexer))
				break ;
		token = ft_new_token(lexer);
		while (++i < NBR_TOKEN)
		{
			if ((ret = lexer->f_tokens[i](lexer, token)) != 0)
			{
				if (ret < 0)
					return (ft_lexer_error(lexer, ret));
				lexer->x += token->size;
				break ;
			}
		}
		if (token->token == END)
			break ;
		if (i >= NBR_TOKEN)
			return (ft_lexer_error(lexer, LEXER_INCONNU));
	}
	return (1);
}
