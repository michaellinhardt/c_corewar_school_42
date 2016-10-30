#include "libft.h"
#include "ft_asm.h"

int		ft_parser_accept(t_parser *parser)
{
	int ret;
	int	i;
	// refaire a partir de la fin
	t_pile_tree *end;
	t_pile_tree *prev;

	end = parser->end_pile;
	while (end)
	{
		i = 0;
		while (i < NBR_ACCEPT)
		{
			ret = parser->f_accept[i](parser, end);
			if (ret == 1)
			{
				end = parser->end_pile;
				continue ;
				// tant qu'on a des accept on continue de reduire
				//return (ACCEPT);
			}
			else if (ret == -1)
			{
				ft_putendl("Error accept");
				return (0);
			}
			else if (ret == CODE_ACCEPT)
				return CODE_ACCEPT;
			++i;
		}
		end = end->prev;
	}
	return (SHIFT);
}
