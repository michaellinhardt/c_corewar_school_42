#include "libft.h"
#include "ft_asm.h"

int		ft_parser_reduce(t_token *token)
{

	ft_display_type_token(token->token);
	if (token->value)
		ft_putendl(token->value);
	ft_putendl("");
	return (1);
}
