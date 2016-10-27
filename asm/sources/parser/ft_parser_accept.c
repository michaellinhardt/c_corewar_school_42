#include "libft.h"
#include "ft_asm.h"

int		ft_parser_accept(t_parser *parser)
{
	int ret;
	int	i;
	// refaire a partir de la fin
	t_pile_tree *begin;

	begin = parser->debut_pile;
	while (begin)
	{
		i = 0;
		while (i < NBR_ACCEPT)
		{
			ret = parser->f_accept[i](parser, begin);
			if (ret > 0)
			{
				// tant qu'on a des accept on continue de reduire
				return (ACCEPT);
			}
			if (ret == -1)
			{
					ft_putendl("Error accept");
					return (0);
			}
			++i;
		}
		/*
			if (ft_check_header(begin, parser))
			{
				parser->memory.header = 1;
				begin->value = HEADER;
				parser->focus_pile = 0;
				return (SHIFT);
			}
			// il faut check pour virgules et tout le bordel
			if (ft_check_separator_char(begin , parser))
			{
				// la regle n'est pas finis 
				return (ACCEPT);
			}
			*/
			// apres faut checker pour les '\n'
			//


			// pour finir on check pour linstruction
			//
			//

			// en en epilogue on check pour le LABEL
			// ca fait une sorte de lecture de droite a gauche de nos regles
		begin = begin->next;
	}
	return (SHIFT);
}
