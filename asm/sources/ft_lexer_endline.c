#include "ft_asm.h"

#include "libft.h"
int		ft_lexer_endline(t_lexer *lexer, t_token *token)
{
	if (*(lexer->focus) == '\n')
	{
		token->token = ENDLINE;
		ft_putnbr(lexer->size_line);
		lexer->size_line = 0;
		lexer->focus = 0;
		return (1);
	}
	return (0);
}
