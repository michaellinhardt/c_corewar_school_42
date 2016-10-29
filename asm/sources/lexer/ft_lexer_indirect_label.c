#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_indirect_label(t_lexer *lexer, t_token *token)
{
	int i;

	if (*(lexer->focus) != ':')
		return (0);
	i = 1;
	while (i < lexer->size_line && ft_memchr(LABEL_CHARS, *(lexer->focus + i),
				37))
		++i;
	if (i == 1)
		return (0);
	ft_get_value(lexer, token, i);
	lexer->focus += i;
	token->token = INDIRECT_LABEL;
	lexer->size_line -= i;
	/*
	if (ft_check_label_char(token->value, token->size))
		return (1);
		*/
	return (1);
}
