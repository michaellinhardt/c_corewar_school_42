/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:42:20 by abary             #+#    #+#             */
/*   Updated: 2016/10/31 21:42:25 by abary            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_lexer lexer;
	t_parser parser;

	ft_bzero(&lexer, sizeof(t_lexer));
	ft_init_parser(&parser);
	ft_init_lexer(&lexer);
	if (argc == 1)
		return (0);
	lexer.fd = ft_open_file(argv);
	lexer.size = ft_get_size_file(lexer.fd);
	lexer.name = *(argv + 1);
	if (lexer.size == -1)
		return (0);
	if (ft_lexer(&lexer, 0, 0))
	{
		if (ft_parser(lexer.begin, &parser))
			ft_compilation(parser.debut_pile->tree, &parser, &lexer);
	}
	ft_destruct_lexer(&lexer);
	ft_destruct_parser(&parser);
	return (0);
}
