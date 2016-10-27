#include "libft.h"
#include "ft_asm.h"

int		ft_compilation(t_parse_tree *tree, t_parser *parser)
{
//	typedef unsigned char	(*f_compilation[ENDLINE])(t_parse_tree *tree);

	t_compile compile;

	compile.code = 0;
	compile.total_size = 0;
	ft_init_compilation(&compile);
	ft_putendl("test compilation");
	ft_bzero(&compile.header, sizeof(t_header));
	ft_init_instructions(compile.inst);
	ft_putendl("---------------");
	ft_compile(tree, &compile, compile.code);



	ft_putendl("Resultat :");
	ft_printf("name header :%s\n", compile.header.prog_name);
	ft_printf("comment header :%s\n", compile.header.comment);
	ft_putendl("code ");
	ft_print_memory(compile.code, compile.total_size);
	return (1);
}
