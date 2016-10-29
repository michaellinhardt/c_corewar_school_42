#include "libft.h"
#include <stdlib.h>
#include "ft_asm.h"

void		ft_parse_error(t_parser *parser, int erreur, t_token *token)
{

	ft_printf("Invalid syntax near : ");
	if (token)
	{
		if (token->token == SEPARATOR)
			ft_printf("%s,", RED);
		else if (token->value)
			ft_printf("%s%s,", RED, token->value);
		ft_putnbr(token->token);
		ft_putstr(NEUTRE);
		ft_putstr(" at : ");
		ft_printf("[%d:", token->y);
		ft_printf("%d]", token->x + 1);
		ft_putchar('\n');
	}
//	exit (1);
}
