/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:42:35 by abary             #+#    #+#             */
/*   Updated: 2016/10/31 21:42:39 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_asm.h"
#include <unistd.h>
#include "libft.h"

void	ft_free_tokens(t_token *token)
{
	if (token)
		ft_free_tokens(token->next);
	if (token)
	{
		if (token->value)
			free(token->value);
		free(token);
		token = 0;
	}
}

void	ft_destruct_lexer(t_lexer *lexer)
{
	if (lexer->fd != 1)
		close(lexer->fd);
	ft_free_tokens(lexer->begin);
	if (lexer->line)
		free(lexer->line);
	lexer = 0;
}

void	ft_destruct_parse_tree(t_parse_tree *parser)
{
	int i;

	if (parser)
	{
		i = 0;
		while (i < parser->nbr_fils)
		{
			ft_destruct_parse_tree(parser->fils[i++]);
		}
		if (parser->fils)
			free(parser->fils);
		free(parser);
		parser = 0;
	}
}

void	ft_destruct_parser(t_parser *parser)
{
	t_pile_tree *pile;

	pile = parser->debut_pile;
	while (pile)
	{
		ft_destruct_parse_tree(pile->tree);
		pile = pile->next;
	}
}
