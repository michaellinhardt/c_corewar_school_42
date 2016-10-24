#include "ft_asm.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
int		ft_lexer(t_lexer *lexer)
{
	int		i;
	int		ret;
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
			if (!(lexer->line = ft_get_line(lexer->fd, lexer)))
				break ;
			lexer->focus = lexer->line;
		}
		if (!(token = ft_new_token(lexer)))
			return (0);
		while (++i < NBR_TOKEN)
		{
			if ((ret = lexer->f_tokens[i](lexer, token)) != 0)
			{
				if (ret < 0)
				{
					ft_lexer_error(lexer, ret);
					return (0);
				}
				break ;
			}
		}
		if (i >= NBR_TOKEN || token->token == END)
			break ;
		/*
				test++;
		if (test == 55)
		break; // pour les tests
		*/
	}
	if (lexer->line)
	{

				free(lexer->line);
				lexer->line = 0;
	}
	ft_display_tokenisation(lexer->begin);
	return (1);
}
