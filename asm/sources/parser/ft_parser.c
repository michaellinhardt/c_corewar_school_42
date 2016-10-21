#include "libft.h"
#include "ft_asm.h"

// on parse d'abord l'header
static int 	ft_parser_header(t_parser *parser)
{
	int ret;

	ret = 1;
	while (1)
	{
		if (ret == 1)
			ret = ft_parser_shift(parser);
		if (ret == 2)
			ret = ft_parser_reduce(parser);
		if (ret != 1 && ret != 2)
			return (ret);
	}
	return (ret);
}

static int	ft_parse_code(t_token **token, t_parser *parser)
{

	(void)token;
	(void)parser;

	return (1);
}

int		ft_parser(t_token *token, t_parser *parser)
{
	(void)token;
	(void)parser;

	parser->focus = token; // shift
	ft_putendl("debut parser");

	if (ft_parser_header(parser))
		return (ft_parse_code(&parser->focus, parser));
	return (0);
}
