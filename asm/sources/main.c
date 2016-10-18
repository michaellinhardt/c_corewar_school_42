#include "ft_asm.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_lexer lexer;

	ft_bzero(&lexer, sizeof(t_lexer));
	ft_init_lexer(&lexer);
	if (argc == 1)
		return (0);
	lexer.fd = ft_open_file(argv);
	lexer.size = ft_get_size_file(lexer.fd);
	if (lexer.size == -1)
		return (0);
	ft_lexer(&lexer);
	return (0);
}
