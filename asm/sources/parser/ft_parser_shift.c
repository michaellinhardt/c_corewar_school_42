#include "ft_asm.h"
#include "libft.h"

int		ft_parser_shift(t_parser *parser)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < NBR_SHIFT)
	{
		ret = parser->f_shift[i](parser);
		if (ret == -1)
		{
			ft_putnbr(i);
			ft_putendl("erreur shift");
			return (ret);
		}
		if (ret > 0)
			return (ret);
		++i;
	}
	return (ret);
}
