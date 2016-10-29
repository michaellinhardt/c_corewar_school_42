#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

int	ft_accept_header(t_parser *parser, t_pile_tree *pile)
{
	if (pile->prev && (pile->value == CMD_NAME || pile->value == CMD_COMMENT))
	{
		if (pile->value == CMD_NAME)
		{
			if (pile->prev->value == CMD_COMMENT)
			{
				pile->value = HEADER;
				ft_add_leaf(pile->tree, pile->prev->tree->fils[0]);
				free(pile->prev->tree->fils);
				free(pile->prev->tree);
				ft_free_elem_pile(pile->prev, parser);
				ft_putendl("accept header");
			}
			else
			{
				ft_parse_error(parser, 0, pile->tree->token);
				return (-1);
			}
		}
		else if (pile->value == CMD_COMMENT)
		{
			if (pile->prev->value == CMD_NAME)
			{
				pile->prev->value = HEADER;
				ft_add_leaf(pile->prev->tree, pile->tree->fils[0]);
				free(pile->tree->fils);
				free(pile->tree);
				ft_free_elem_pile(pile, parser);
				ft_putendl("accept header");
			}
			else
			{
				ft_parse_error(parser, 0, pile->tree->token);
				return (-1);
			}
		}
	}
	return (0);
}

int	ft_accept_label(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_INST || pile->value == ENDLINE)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == POSITION)
		{
			ft_putendl("accept label");
			ft_fusion_fils(pile->prev->tree, pile->tree);
			free(pile->tree->fils);
			pile->tree->fils = 0;
			pile->tree->nbr_fils = 0;
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->prev->tree = pile->tree;
			ft_free_elem_pile(pile, parser);
			pile->prev->value = FIN_LABEL;
			return (1);
		}
	}
	return (0);
}

int	ft_accept_label_inst(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CPL_INST)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == FIN_LABEL)
		{
			ft_putendl("accept label + inst");
			ft_fusion_fils(pile->prev->tree, pile->tree);
			free(pile->tree->fils);
			pile->tree->fils = 0;
			pile->tree->nbr_fils = 0;
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->prev->tree = pile->tree;
			ft_free_elem_pile(pile, parser);
			pile->prev->value = FIN_LABEL;
			return (1);
		}
	}
	return (0);
}


int	ft_accept_name(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_LINE)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == MINI_NAME)
		{
			ft_putendl("accept mini name");
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->prev->tree = pile->tree;
			pile->prev->value = CMD_NAME;
			ft_free_elem_pile(pile, parser);
			return (1);
		}
	}
	return (0);
}

int	ft_accept_comment(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_LINE)
	{

		if (!pile->prev)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == MINI_COMMENT)
		{
			ft_putendl("accept mini commment ");
			ft_add_leaf(pile->tree, pile->prev->tree);
			pile->prev->tree = pile->tree;
			pile->prev->value = CMD_COMMENT;
			ft_free_elem_pile(pile, parser);
			return (1);
		}
	}
	return (0);
}

int	ft_accept_argument(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_LINE)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value == POSITION || pile->prev->value == MINI_NAME
				|| pile->prev->value == MINI_COMMENT)
			return (0);
		if (pile->prev->value == ARG)
		{
			ft_putendl("accept last arg");
			pile->value = LAST_ARG;
			ft_add_leaf(pile->tree, pile->prev->tree);
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
		ft_putendl("lalala");
		ft_parse_error(parser, 0, pile->prev->tree->token);
		return (-1);

	}
	return (0);
}

int	ft_accept_separator_char(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == LAST_ARG)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}	
		if (pile->prev->value == INST)
			return (0);
		if (pile->prev->value == VIRGULE)
		{
			ft_putendl("accept separator char");
			pile->value = LAST_ARG;
			ft_add_leaf(pile->tree, pile->prev->tree);
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
		else
		{
			ft_parse_error(parser, 0, pile->prev->tree->token);
			return (-1);
		}
	}
	return (0);
}

static void	ft_complete_instruction(t_parse_tree *inst, t_parse_tree *args)
{

	if (args)
	{
		int i;

		i = args->nbr_fils - 1;
		if (args->token->value)
			ft_add_leaf(inst, args);
		while (i >= 0)
		{
			ft_complete_instruction(inst, args->fils[i]);
			i--;
		}
	}
}

int	ft_accept_instruction(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == LAST_ARG)
	{
		if (!pile->prev)
				ft_putendl("erreur accept instruction");
		if (pile->prev->value == VIRGULE)
			return (0);
		if (pile->prev->value == INST)
		{
			if (ft_verif_instruction(pile->prev, pile, parser->inst))
			{

				ft_complete_instruction(pile->prev->tree, pile->tree);
				pile->prev->value = CPL_INST;
				ft_free_arguments(pile->tree);
				pile->tree->fils = 0;
				pile->tree->nbr_fils = 0;
				ft_add_leaf(pile->tree, pile->prev->tree);
				pile->prev->tree = pile->tree;
				ft_free_elem_pile(pile, parser);
				return (1);
			}
			else
			{
				ft_putendl("erreur accept: instruction invalide");
				ft_parse_error(parser, 0, pile->tree->token);
			}
			return (0);
		}
		else
		{
			ft_parse_error(parser, 0, pile->tree->token);
			return (-1);
		}
	}
	return (0);
}

int			ft_accept_code_header(t_parser *parser, t_pile_tree *pile)
{
	//reduction final
	if (pile->value == FIN_INST)
	{
		if (pile->prev->value != HEADER)
			return (0);
		ft_putendl("reduction final");
		ft_add_leaf(pile->prev->tree, pile->tree);
		ft_free_elem_pile(pile, parser);
		return (CODE_ACCEPT);
	}
	return (0);
}

int			ft_accept_end_inst(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_INST)
	{
		if (pile->prev->value == CPL_INST)
		{
			ft_putendl("accept instruction multiples");
			pile->prev->tree = ft_fusion_fils(pile->prev->tree, pile->tree);
			pile->prev->value = FIN_INST;
			free(pile->tree->fils);
			pile->tree->fils = 0;
			pile->tree->nbr_fils = 0;
			ft_free_elem_pile(pile, parser);
			return (1);
		}
	}
	return (0);
}

int			ft_accept_end(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN)
	{
		if (pile->prev->value == CPL_INST)
		{
			ft_putendl("accept fin instruction");
			pile->prev->value = FIN_INST;
			ft_free_elem_pile(pile, parser);
			return (1);
		}
		// ajouter condion poour label finis
		else 
		{
			ft_parse_error(parser, 0, pile->tree->token);
			ft_putendl("erreur accept end");
			return (-1);
		}
	}
	return (0);
}
