#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

int		ft_accept_argument(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_LINE)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, -12, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == POSITION || pile->prev->value == MINI_NAME
				|| pile->prev->value == MINI_COMMENT)
			return (0);
		if (pile->prev->value == ARG)
		{
			pile->value = LAST_ARG;
			ft_add_leaf(pile->tree, pile->prev->tree);
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
		if (pile->prev->tree && pile->prev->tree->fils)
			return (ft_parse_error(parser, LAST_ARG,
						pile->prev->tree->fils[0]->token));
		else
			return (ft_parse_error(parser, LAST_ARG, parser->focus));
	}
	return (0);
}

int		ft_accept_separator_char(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == LAST_ARG)
	{
		if (!pile->prev)
			return (ft_parse_error(parser, -13, pile->tree->token));
		if (pile->prev->value == INST)
			return (0);
		if (pile->prev->value == VIRGULE)
		{
			pile->value = LAST_ARG;
			ft_add_leaf(pile->tree, pile->prev->tree);
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
		else
		{
			if (pile->tree && pile->tree->fils)
				return (ft_parse_error(parser,
							LAST_ARG, pile->tree->fils[0]->token));
			else
				return (ft_parse_error(parser, LAST_ARG, parser->focus));
		}
	}
	return (0);
}

int		ft_accept_label_inst(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CPL_INST || pile->value == FIN_LINE)
	{
		if (!pile->prev)
			return (ft_parse_error(parser, 0, parser->focus));
		if (pile->prev->value != POSITION)
			return (0);
		if (pile->value == FIN_LINE)
		{
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->value = POSITION_INST;
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
		ft_add_leaf(pile->prev->tree, pile->tree->fils[0]);
		free(pile->tree->fils);
		pile->tree->nbr_fils = 0;
		pile->tree->fils = 0;
		ft_add_leaf(pile->tree, pile->prev->tree);
		ft_free_elem_pile(pile->prev, parser);
		pile->value = POSITION_INST;
		return (1);
	}
	return (0);
}

int		ft_accept_position_inst(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CPL_INST)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept label inst");
			return (-1);
		}
		if (pile->prev->value != POSITION_INST)
			return (0);
		pile->prev->tree->fils[0] =
			ft_fusion_fils(pile->prev->tree->fils[0], pile->tree);
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		free(pile->tree);
		pile->tree = 0;
		pile->prev->value = POSITION_INST;
		ft_free_elem_pile(pile, parser);
		return (1);
	}
	return (0);
}
