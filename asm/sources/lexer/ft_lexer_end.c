#include <unistd.h>
#include "ft_asm.h"

int		ft_lexer_end(t_lexer *lexer, t_token *token)
{
	int off;

	off = lseek(lexer->fd, 0, SEEK_CUR);
	if (off == lexer->size && !lexer->size_line)
	{
		token->token = END;
		lexer->focus = 0;
		lexer->size_line = 0;
		return (1);
	}
	return (0);
}
