#include <unistd.h>
#include "ft_asm.h"

int		ft_lexer_string(t_lexer *lexer, t_token *token)
{
	int		size;
	int		ret;

	if (*(lexer->focus) != '"')
		return (0);
	size = 0;
	lexer->focus++;

	while (size < lexer->size_line && *(lexer->focus + size) != '"')
		++size;
	if (!(*lexer->focus + size))
	{
		char c;

		while ((ret = read(lexer->fd, &c, 1)))
		{
			if (c == '"')
				break ;
			if (ret == -1)
				return (0);
			++size;
		}
		if (c != '"')
		{
			return (0); // a faire une erreur 
		}
	}
	ft_get_value(lexer, token, size);
	lexer->focus += size;
	token->token = STRING;
	lexer->size_line -= size;
	return (1);
}
