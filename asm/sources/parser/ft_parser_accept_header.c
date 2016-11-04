#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

static int	ft_accept_h_name_comment(t_parser *parser, t_pile_tree *pile)
{
	pile->value = HEADER;
	ft_add_leaf(pile->tree, pile->prev->tree->fils[0]);
	free(pile->prev->tree->fils);
	free(pile->prev->tree);
	ft_free_elem_pile(pile->prev, parser);
	return (1);
}

static int	ft_accept_h_comment_name(t_parser *parser, t_pile_tree *pile)
{
	pile->prev->value = HEADER;
	ft_add_leaf(pile->prev->tree, pile->tree->fils[0]);
	free(pile->tree->fils);
	free(pile->tree);
	ft_free_elem_pile(pile, parser);
	return (1);
}

int			ft_accept_header(t_parser *parser, t_pile_tree *pile)
{
	if (pile->prev && (pile->value == CMD_NAME || pile->value == CMD_COMMENT))
	{
		if (pile->value == CMD_NAME)
		{
			if (pile->prev->value == CMD_COMMENT)
				return (ft_accept_h_name_comment(parser, pile));
			else
				return (ft_parse_error(parser, CPL_INST, pile->tree->token));
		}
		else if (pile->value == CMD_COMMENT)
		{
			if (pile->prev->value == CMD_NAME)
			{
				return (ft_accept_h_comment_name(parser, pile));
			}
			else
				return (ft_parse_error(parser, CPL_INST, pile->tree->token));
		}
	}
	return (0);
}

int			ft_accept_name(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_LINE)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, -11, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == MINI_NAME)
		{
			ft_putendl("accept mini name");
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->value = CMD_NAME;
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
	}
	return (0);
}

int			ft_accept_comment(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_LINE)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, -10, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == MINI_COMMENT)
		{
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->value = CMD_COMMENT;
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
	}
	return (0);
}
