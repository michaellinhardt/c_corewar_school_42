#include "libft.h"
#include "ft_asm.h"

static void	ft_display_type_token(int token)
{
	ft_putchar('[');
	if (token == COMMAND_COMMENT)
		ft_putstr("COMMAND_COMMENT");
	else if (token == COMMAND_NAME)
		ft_putstr("COMMAND_COMMENT");
	else if (token == STRING)
		ft_putstr("STRING");
	else if (token == WHITESPACE)
		ft_putstr("WHITESPACE");
	ft_putchar(']');
}

void		ft_display_tokenisation(t_token *begin)
{

	ft_putendl("TOKENIZACHION !!!!");
	while (begin)
	{
		ft_putendl("------------------------------");
		ft_display_type_token(begin->token);	
		if (begin->value)
			ft_putendl(begin->value);
		else
			ft_putendl("(NULL)");
		ft_putendl("------------------------------");
		begin = begin->next;
	}
}
