#include "libft.h"
#include <stdlib.h>
#include "ft_asm.h"

int		ft_parse_error(t_parser *parser, int erreur, t_token *token)
{
	(void)parser;
		if (erreur == CMD_NAME)
			ft_printf("%sincomplete header ", RED);
		else if (erreur == CMD_COMMENT)
			ft_printf("%sincomplete header ", RED);
		else if (erreur == HEADER)
			ft_printf("no code ");
		else if (erreur == CPL_INST)
			ft_printf("%sheader not at top of the file ", RED);
		else if (erreur == MINI_NAME)
			ft_printf("Size of string name is invalid ");
		else if (erreur == MINI_COMMENT)
			ft_printf("Size of string comment is invalid ");
		else
			ft_printf("Invalid syntax near : ");
	if (token)
	{
		if (erreur == LAST_ARG && token->value)
			ft_printf("%s%s", RED, token->value);
		else if (erreur == SEPARATOR)
			ft_printf("%s%s", RED, ",");
		else
			ft_printf("%s%s", RED, token->value);
//		ft_putnbr(erreur);
		ft_putstr(NEUTRE);
		ft_putstr(" at : ");
		ft_printf("[%d:", token->y);
		ft_printf("%d]", token->x + 1);
		ft_putchar('\n');
	}
	return (-1);
//	exit (1);
}
