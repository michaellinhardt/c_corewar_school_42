#include "libft.h"
#include "ft_asm.h"

int		ft_lexer_instruction(t_lexer *lexer, t_token *token)
{
	int i;

	i = 0;

	while (i < lexer->size_line && ft_memchr(LABEL_CHARS, *(lexer->focus + i),
			37))
		++i;
	if (!i || *(lexer->focus + i) == ':')
		return (0);
	ft_get_value(lexer, token, i);
	lexer->focus += i;
	token->token = INSTRUCTION;
	lexer->size_line -= i;
	return (1);
}
