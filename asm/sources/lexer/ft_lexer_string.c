/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:42:43 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:19:58 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_asm.h"
#include "libft.h"

static void	ft_lexer_decal_head(t_lexer *lexer,
		t_token *token, int ret, int size)
{
	lexer->head = ret + size + 1;
	lexer->focus = lexer->line;
	ft_get_value(lexer, token, size + 1);
	token->token = STRING;
	lexer->size_line = 0;
}

static int	ft_lexer_string_new_line(t_lexer *lexer, int size, int i, int ret)
{
	if ((ret = lseek(lexer->fd, -(size + i + 1),
					SEEK_CUR)) == -1)
		return (0);
	if (lexer->line)
	{
		free(lexer->line);
		lexer->line = 0;
	}
	if (!(lexer->line = ft_memalloc(sizeof(char) * (size + i + 2))))
		return (0);
	if (read(lexer->fd, lexer->line, size + i + 1) == -1)
		return (0);
	return (1);
}

static int	ft_lexer_read_string(t_lexer *lexer, t_token *token, int size)
{
	char	c;
	int		ret;
	int		i;

	i = 0;
	while ((ret = read(lexer->fd, &c, 1)))
	{
		if (c == '\n')
			lexer->y++;
		if (c == '"')
			break ;
		++i;
	}
	if (c != '"')
		return (LEXER_STRING);
	else
	{
		if (!(ft_lexer_string_new_line(lexer, size, i, ret)))
			return (0);
		ft_lexer_decal_head(lexer, token, ret, size + i);
	}
	return (1);
}

int			ft_lexer_string(t_lexer *lexer, t_token *token)
{
	int		size;

	if (*(lexer->focus) != '"')
		return (0);
	size = 1;
	while (size < lexer->size_line && *(lexer->focus + size) != '"')
		++size;
	if (!*(lexer->focus + size))
		return (ft_lexer_read_string(lexer, token, size));
	ft_get_value(lexer, token, size + 1);
	lexer->focus += size + 1;
	token->token = STRING;
	lexer->size_line -= size + 1;
	return (1);
}
