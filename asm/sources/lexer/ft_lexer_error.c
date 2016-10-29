#include <unistd.h>
#include "libft.h"
#include "ft_asm.h"

void		ft_lexer_error(t_lexer *lexer, int erreur)
{
	int 	off;
	char	*c;

	ft_putstr("lexical error : ");
	if (erreur == LEXER_STRING)
		ft_putstr("quotes missing ");
	else if (erreur == LEXER_INCONNU)
	{
			ft_printf("token inconnu near : ");
			c = 0;
			if (lexer->focus)
				c = lexer->focus;
			else if (lexer->line)
				c = lexer->line;
			ft_putstr(RED);
			while (c && *c && !ft_isspace(*c))
			{
				ft_putchar(*c++);
			}
			ft_putstr(NEUTRE);
			ft_putchar(' ');
	}
	if (lexer->end)
	{
			ft_putstr("at : ");
			ft_printf("[%d:", lexer->end->y);
			ft_printf("%d]", lexer->end->x + 1);
	}
	ft_putchar('\n');
	ft_free_tokens(lexer->begin);
	if (lexer->line)
		ft_strdel(&(lexer->line));
	close(lexer->fd);
}
