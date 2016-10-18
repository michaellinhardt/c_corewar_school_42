#include "ft_asm.h"
#include "libft.h"
#include <unistd.h>

int		ft_lexer(t_lexer *lexer)
{
	int		i;
	t_token *token;

	while (1)
	{
		i = -1;
		if (!(token = ft_new_token(lexer)))
			return (0);
		while (++i < NBR_TOKEN)
		{
			if (lexer->f_tokens[i](lexer, token))
				break ;
		}
	}
	return (1);
}
