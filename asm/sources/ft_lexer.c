#include "ft_asm.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
int		ft_lexer(t_lexer *lexer)
{
	int		i;
	char	*d;
	static int test = 0;
	t_token *token;

	while (1)
	{
		i = -1;
		if (!lexer->size_line)
		{
			if (lexer->line)
			{
				free(lexer->line);
				lexer->line = 0;
			}
			if (!ft_get_line(lexer->fd, lexer))
				break ;
			lexer->focus = lexer->line;
		}
		if (!(token = ft_new_token(lexer)))
			return (0);
		while (++i < NBR_TOKEN)
		{
			if (lexer->f_tokens[i](lexer, token))
			{
				test++;
				break ;
			}
		}
		if (test == 3)
		break; // pour les tests
	}
	ft_display_tokenisation(lexer->begin);
	return (1);
}
