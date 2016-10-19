#include "ft_asm.h"

int		ft_lexer_endline(t_lexer *lexer, t_token *token)
{
	if (*(lexer->focus) == '\n')
	{
		lexer->focus++;
		token->token = ENDLINE;
		lexer->size_line--;
		return (1);
	}
	return (0);
}
