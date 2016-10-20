#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_indirect_label(t_lexer *lexer, t_token *token)
{
	int i;

	if (*(lexer->focus) != ':')
		return (0);
	i = 1;
	while (i < lexer->size_line && ft_strchr(LABEL_CHARS, *(lexer->focus + i)))
		++i;
	if (i == 1)
		return (0);
	ft_get_value(lexer, token, i);
	lexer->focus += i;
	token->token = INDIRECT_LABEL;
	lexer->size_line -= i;
	return (1);
}
