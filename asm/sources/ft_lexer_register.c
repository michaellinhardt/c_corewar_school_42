#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_register(t_lexer *lexer, t_token *token)
{
	int i;

	if (*(lexer->focus) != 'r')
		return (0);
	i = 1;
	while (i < lexer->size_line && ft_isdigit(*(lexer->focus + i)))
		++i;
	if (!ft_strchr(TERM_CHAR, *(lexer->focus + i))
			|| !ft_isspace(*(lexer->focus + i)))
		return (0);
	ft_get_value(lexer, token, i);
	lexer->focus += i;
	token->token = REGISTER;
	lexer->size_line -= i;
	return (0);
}
