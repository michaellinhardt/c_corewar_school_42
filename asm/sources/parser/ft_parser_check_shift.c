#include "libft.h"
#include "ft_asm.h"

int		ft_shift_no_focus(t_parser *parser)
{
	if (!parser->focus)
		return (-1);
	return (0);
}

int		ft_shift_whitespaces(t_parser *parser)
{
	if (parser->focus->token == WHITESPACE)
	{
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_command_name(t_parser *parser)
{
	if (parser->focus->token == COMMAND_NAME)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_string(t_parser *parser)
{
	if (parser->focus->token == STRING)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_endline(t_parser *parser)
{
	 if (parser->focus->token == ENDLINE)
	{
		/*
		 ** Ignorer les '\n' au debut et les '\n' multiples
		 */
		if (!parser->debut_pile || (parser->end_pile->tree && 
					parser->end_pile->tree->token->token == ENDLINE))
		{
			parser->focus = parser->focus->next;
			return (SHIFT);
		}
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_command_comment(t_parser *parser)
{
	 if (parser->focus->token == COMMAND_COMMENT)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (SHIFT);
	}
	return (0);
}

int		ft_shift_label(t_parser *parser)
{
	if (parser->focus->token == LABEL)
	{
		/*
		 **	a voir apres
		 */
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_instruction(t_parser *parser)
{
	 if (parser->focus->token == INSTRUCTION)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_register(t_parser *parser)
{
	if (parser->focus->token == REGISTER)
	{
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		parser->focus_pile->value = ARG;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_separator_char(t_parser *parser)
{
	if (parser->focus->token == SEPARATOR)
	{
		if (parser->focus_pile)
		{
			ft_putendl("erreur shift separator char");
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_direct_label(t_parser *parser)
{
	if (parser->focus->token == DIRECT_LABEL)
	{
		if (parser->focus_pile)
		{
			ft_putendl("erreur shift direct label");
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_direct(t_parser *parser)
{
	if (parser->focus->token == DIRECT)
	{
		if (parser->focus_pile)
		{
			ft_putendl("erreur shift direct");
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}

int		ft_shift_indirect(t_parser *parser)
{
	if (parser->focus->token == INDIRECT)
	{
		if (parser->focus_pile)
		{
			ft_putendl("erreur shift indirect");
			return (-1);
		}
		ft_add_tree_shift(parser);
		parser->focus_pile->value = ARG;
		parser->focus = parser->focus->next;
		return (REDUCE);
	}
	return (0);
}
