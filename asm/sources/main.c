/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:42:20 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:19:37 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_little_to_big(int little)
{
	return ((little << 24 & 0xFF000000) | (little << 8 & 0xFF0000)
				| (little >> 8 & 0xFF00) | (little >> 24 & 0xFF));
}

void	ft_make_it(char **argv, int s)
{
	t_lexer		lexer;
	t_parser	parser;

	ft_bzero(&lexer, sizeof(t_lexer));
	ft_init_parser(&parser);
	ft_init_lexer(&lexer);
	lexer.fd = ft_open_file(argv);
	lexer.size = ft_get_size_file(lexer.fd);
	lexer.name = *argv;
	if (lexer.size == -1)
		return ;
	if (ft_lexer(&lexer, 0, 0))
	{
		if (s)
			ft_display_tokenisation(lexer.begin);
		if (ft_parser(lexer.begin, &parser))
			ft_compilation(parser.debut_pile->tree, &parser, &lexer);
	}
	ft_destruct_lexer(&lexer);
	ft_destruct_parser(&parser);
}

int		main(int argc, char **argv)
{
	char	**save;
	int		s;

	s = 0;
	save = argv;
	if (argc == 1)
		return (0);
	while (*++argv)
	{
		if (!ft_strcmp("-s", *argv))
		{
			s = 1;
			break ;
		}
	}
	argv = save;
	while (*++argv)
	{
		if (!ft_strcmp("-s", *argv))
			++argv;
		if (*argv)
			ft_make_it(argv, s);
	}
}
