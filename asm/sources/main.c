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
