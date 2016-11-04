#include "libft.h"
#include "ft_asm.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_write_code(unsigned char *code, t_lexer *lexer, t_header *header)
{
	int				fd;

	header->magic = ft_little_to_big(COREWAR_EXEC_MAGIC);
	if ((fd = ft_create_file(lexer->name)) != -1)
	{
		write(fd, header, sizeof(t_header));
		write(fd, code, ft_little_to_big(header->prog_size));
		close(fd);
	}
	if (code)
		free(code);
}

int			ft_compilation(t_parse_tree *tree, t_parser *parser, t_lexer *lexer)
{
	t_compile		compile;
	unsigned char	*code;
	unsigned int	poids;
	unsigned int	size;

	(void)parser;
	poids = 0;
	compile.code = 0;
	compile.total_size = 0;
	code = 0;
	ft_bzero(&compile.header, sizeof(t_header));
	ft_init_instructions(compile.inst);
	size = ft_calcul_poids(tree, compile.inst, poids);
	if (ft_search_label(tree, tree))
	{
		ft_putendl("erreur compilation label search");
		return (0);
	}
	size = ft_compile(tree, &code, &compile, 0);
	compile.header.prog_size = ft_little_to_big(size);
	ft_write_code(code, lexer, &compile.header);
	return (1);
}
