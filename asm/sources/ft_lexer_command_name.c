#include "libft.h"
#include <unistd.h>
#include "ft_asm.h"

int		ft_lexer_command_name(t_lexer *lexer, t_token *token)
{
	if (*(lexer->line) != '.')
		return (0);
	if (lexer->size_line > 4 && !ft_strncmp(NAME_CMD_STRING, lexer->focus, 5))
	{
		ft_get_value(lexer, token, 6); 
		lexer->focus += 5;
		token->token = COMMAND_NAME;
		lexer->size_line -= 5;
		return (1);
	}
	return (0);
}
