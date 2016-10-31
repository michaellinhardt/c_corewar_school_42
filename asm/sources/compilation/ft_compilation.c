#include "libft.h"
#include "ft_asm.h"


#include <stdlib.h>
#include <unistd.h>
int		ft_compilation(t_parse_tree *tree, t_parser *parser, t_lexer *lexer)
{
	(void)parser;
	//	typedef unsigned char	(*f_compilation[ENDLINE])(t_parse_tree *tree);
	t_compile compile;
	unsigned int poids;
	unsigned int size;
	int			fd;

	poids = 0;
	compile.code = 0;
	compile.total_size = 0;
	ft_putendl("test compilation");
	ft_bzero(&compile.header, sizeof(t_header));
//	ft_create_header(&compile.header, token);
	ft_init_instructions(compile.inst);
	ft_putendl("---------------");
	size = ft_calcul_poids(tree, compile.inst, poids);

	ft_putnbr(size);

	if (ft_search_label(tree, tree))
	{
			ft_putendl("erreur compilation label search");
	}
	unsigned char	*code;

	code = 0;
	size = ft_compile(tree, &code, &compile, 0);
	compile.header.prog_size = ft_little_to_big(size);
	compile.header.magic = ft_little_to_big(COREWAR_EXEC_MAGIC);
	if ((fd = ft_create_file(lexer->name)) != -1)
	{
		ft_putendl("ecriture du code");
		write(fd, &compile.header, sizeof(t_header));
		write(fd, code, size);
		close (fd);
	}
	free(code);

	return (1);
	//	ft_print_memory(compile.code, compile.total_size);
}
