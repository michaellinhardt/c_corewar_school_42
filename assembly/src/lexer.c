/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 08:28:57 by pba               #+#    #+#             */
/*   Updated: 2016/10/01 16:17:37 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_tlist						*tokenize(char *str)
{
	int						i;
	char					**terms;
	t_tlist					*list;

	list = NULL;
	terms = NULL;
	//str = epur_str(str, ',');
	terms = ft_strsplit(str, ' ');
	i = 0;
	while (terms[i])
	{
		ft_putendl(terms[i]);
		++i;
		//list = dilst_append(list, );
		//list->last->kind = find_kind(terms[i]);
	}
	return (list);
}

t_tlist						**lexer(int fd)
{
	int						i;
	char					*line;
	t_tlist					*lex;
	static t_tlist			*tab[1000];

	lex = NULL;
	ft_memset(tab, 0, sizeof(t_tlist *) * 1000);
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < 999)
	{
		lex = tokenize(line);
		tab[i] = lex;
		ft_memset(line, 0, ft_strlen(line));
		++i;
	}
	return (tab);
}
