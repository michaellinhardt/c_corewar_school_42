#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_indirect(t_lexer *lexer, t_token *token)
{
	int i;

	if (*(lexer->focus) != '-' && !ft_isdigit(*(lexer->focus)))
		return (0);
	i = *(lexer->focus) == '-' ? 1 : 0;
	while (i < lexer->size_line && ft_isdigit(*(lexer->focus + i)))
		++i;
	if ((*(lexer->focus) == '-' && i == 1)
			|| (*(lexer->focus) != '-' && i == 0))
		return (0);
	if (!ft_isspace(*(lexer->focus + i)) && *(lexer->focus + i) != ',')
		return (0);
	ft_get_value(lexer, token, i);
	lexer->focus += i;
	token->token = INDIRECT;
	lexer->size_line -= i;
	return (1);
}
