#include "libft.h"
#include "ft_asm.h"

static void	ft_display_type_token(int token)
{
	ft_putchar('[');
	if (token == COMMAND_COMMENT)
		ft_putstr("COMMAND_COMMENT");
	else if (token == COMMAND_NAME)
		ft_putstr("COMMAND_NAME");
	else if (token == STRING)
		ft_putstr("STRING");
	else if (token == WHITESPACE)
		ft_putstr("WHITESPACE");
	else if (token == COMMENT)
		ft_putstr("COMMENT");
	else if (token == SEPARATOR)
		ft_putstr("SEPARATOR");
	else if (token == LABEL)
		ft_putstr("LABEL");
	else if (token == REGISTER)
		ft_putstr("REGISTER");
	else if (token == INSTRUCTION)
		ft_putstr("INSTRUCTION");
	else if (token == INDIRECT)
		ft_putstr("INDIRECT");
	else if (token == DIRECT_LABEL)
		ft_putstr("DIRECT_LABEL");
	else if (token == DIRECT)
		ft_putstr("DIRECT");
	else if (token == ENDLINE)
		ft_putstr("ENDLINE");
	else if (token == END)
		ft_putstr("END");
	else if (token == INDIRECT_LABEL)
		ft_putstr("INDIRECT_LABEL");
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
