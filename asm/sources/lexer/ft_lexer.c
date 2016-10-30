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
			lexer->x= 0;
		}
		if (!(token = ft_new_token(lexer)))
			return (0);
		else
		{
			token->y = lexer->y;
			token->x = lexer->x;
		}
		while (++i < NBR_TOKEN)
		{
			if ((ret = lexer->f_tokens[i](lexer, token)) != 0)
			{
				if (ret < 0)
				{
					ft_lexer_error(lexer, ret);
					return (0);
				}
				lexer->x += token->size;
				break ;
			}
		}
		if (token->token == END)
			break ;
		if (i >= NBR_TOKEN)
		{
			ft_lexer_error(lexer, LEXER_INCONNU);
			return (0);
		}
	}
	if (lexer->line)
	{
		free(lexer->line);
		lexer->line = 0;
	}
	ft_display_tokenisation(lexer->begin);
	return (1);
}
