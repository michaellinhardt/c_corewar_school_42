#include <unistd.h>
#include "libft.h"
#include "ft_asm.h"

void		ft_lexer_error(t_lexer *lexer, int erreur)
{
	int off;

	if (erreur == DB_QUOTES)
	{
		ft_putnbr(lexer->y);
		ft_putchar(':');
		off = lseek(lexer->fd, 0, SEEK_CUR);
		if (off)
			ft_putnbr(lexer->y / off);
		else
			ft_putnbr(0);
		ft_putendl("db quotes missing");
	}
	ft_free_tokens(lexer->begin);
	if (lexer->line)
		ft_strdel(&(lexer->line));
	close(lexer->fd);
}
