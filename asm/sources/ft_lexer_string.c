#include <unistd.h>
#include <stdlib.h>
#include "ft_asm.h"

#include "libft.h"
static int ft_lexer_read_string(t_lexer *lexer, t_token *token, int size)
{
	char 	c;
	int 	ret;
	int 	i;

	i = 0;
	while ((ret = read(lexer->fd, &c, 1)))
	{
		if (c == '"')
			break ;
		if (ret == -1)
			return (0);
		++i;
	}
	if (c != '"')
		return (0); // a faire une erreur 
	else
	{
		if ((ret = lseek(lexer->fd, -(size + i + 1),
				   	SEEK_CUR)) == -1)
			return (0);
		if (lexer->line)
			free(lexer->line);
		if (!(lexer->line = ft_memalloc(sizeof(char) * (size + i + 2))))
			return (0);
		if (read(lexer->fd, lexer->line, size + i + 1) == -1)
			return (0);
		lexer->head = ret + size + i + 1;
		lexer->focus = lexer->line;
		ft_get_value(lexer, token, size + i + 1);
		token->token = STRING;
		lexer->size_line = 0;
	}
	return (1);
}

int		ft_lexer_string(t_lexer *lexer, t_token *token)
{
	int		size;

	if (*(lexer->focus) != '"')
		return (0);
	size = 1;
	while (size < lexer->size_line && *(lexer->focus + size) != '"')
		++size;
	if (!*(lexer->focus + size))
		return (ft_lexer_read_string(lexer, token, size));	
	ft_get_value(lexer, token, size + 1);
	lexer->focus += size + 1;
	token->token = STRING;
	lexer->size_line -= size + 1;
	return (1);
}
