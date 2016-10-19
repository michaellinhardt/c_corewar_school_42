#include "ft_asm.h"
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
int		ft_lexer(t_lexer *lexer)
{
	int		i;
	static int test = 0;
	t_token *token;

	while (1)
	{
		i = 0;
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
			ft_putstr(lexer->focus);
		}
		if (!(token = ft_new_token(lexer)))
			return (0);
		while (++i < NBR_TOKEN)
		{
			if (lexer->f_tokens[i](lexer, token))
			{
				break ;
			}
		}
		/*
		if (lexer->focus)
		ft_putstr(lexer->focus);
		*/
				test++;
		if (test == 10)
		break; // pour les tests
	}
	ft_display_tokenisation(lexer->begin);
	return (1);
}
