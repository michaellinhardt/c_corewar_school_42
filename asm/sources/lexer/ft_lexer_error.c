#include <unistd.h>
#include "libft.h"
#include "ft_asm.h"

void		ft_display_lexer_error_fin(t_lexer *lexer)
{
	if (lexer->end)
	{
		ft_putstr("at : ");
		ft_printf("[%d:", lexer->end->y);
		ft_printf("%d]", lexer->end->x + 1);
	}
	ft_putchar('\n');
}

int			ft_lexer_error(t_lexer *lexer, int erreur)
{
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
	ft_display_lexer_error_fin(lexer);
	return (0);
}
