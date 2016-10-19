#include <stdlib.h>
#include "ft_asm.h"

void	ft_free_tokens(t_token *token)
{
	if (token)
		ft_free_tokens(token->next);
	if (token)
	{
		if (token->value)
			free(token->value);
		free(token);
		token = 0;
	}
}
