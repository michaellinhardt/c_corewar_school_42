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
				ft_parse_error(parser, CPL_INST, pile->tree->token);
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
				ft_parse_error(parser, CPL_INST, pile->tree->token);
				return (-1);
			}
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
		ft_parse_error(parser, -1, pile->prev->tree->token);
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
			ft_parse_error(parser, LAST_ARG, pile->tree->fils[0]->token);
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
		{
				ft_putendl("erreur accept instruction");
				return (-1);
		}
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

int			ft_accept_instruction_plus(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CPL_INST)
	{
		if (!pile->prev)
		{
			ft_parse_error(parser, CPL_INST, pile->tree->token);
			return (-1);
		}
		if (pile->prev->value != CPL_INST)
			return (0);
		ft_putendl("accept multiple instruciotn ");
		pile->prev->tree = ft_fusion_fils(pile->prev->tree, pile->tree);
		pile->prev->value = CPL_INST;
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		ft_free_elem_pile(pile, parser);
		return (1);
	}
	return (0);
}

int		ft_accept_fin(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept  fin");
			return (-1);
		}
		if (pile->prev->value != CPL_INST && pile->prev->value != POSITION_INST)
		{
			ft_parse_error(parser, pile->prev->value, pile->prev->tree->token);
			return (-1);
		}
		if (pile->prev->value == HEADER)
		{
			ft_parse_error(parser, pile->prev->value, pile->prev->tree->token);
			return (-1);
		}
		pile->prev->value = CODE_FIN;
		ft_free_elem_pile(pile, parser);
		return (1);
	}
	return (0);
}

int		ft_accept_code_fin(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CODE_FIN || pile->value == CODE_FIN)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept code fin");
			return (-1);
		}
		if (pile->prev->value != HEADER && pile->prev->value != CPL_INST &&
				pile->prev->value != POSITION_INST)
		{
			ft_putendl("erreur code fin");
		   return (-1);	
		}
		ft_putendl("accept label + inst");
		ft_fusion_fils(pile->prev->tree, pile->tree);
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		ft_add_leaf(pile->tree, pile->prev->tree);
		pile->prev->tree = pile->tree;
		ft_free_elem_pile(pile, parser);
		pile->prev->value = CODE_FIN;
		if (parser->debut_pile == parser->end_pile)
			return (CODE_ACCEPT);
		return (1);
	}
	return (0);
}


int		ft_accept_label_inst(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == CPL_INST || pile->value == FIN_LINE)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept label inst");
			return (-1);
		}
		if (pile->prev->value != POSITION)
			return (0);
		ft_putendl("accept label + inst");
		ft_fusion_fils(pile->prev->tree, pile->tree);
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		ft_add_leaf(pile->tree, pile->prev->tree);
		pile->prev->tree = pile->tree;
		ft_free_elem_pile(pile, parser);
		pile->prev->value = POSITION_INST;
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
		ft_putendl("accept positoin inst  + inst");
		ft_fusion_fils(pile->prev->tree->fils[0], pile->tree);
		free(pile->tree->fils);
		pile->tree->fils = 0;
		pile->tree->nbr_fils = 0;
		ft_add_leaf(pile->tree, pile->prev->tree->fils[0]);
		pile->prev->tree = pile->tree;
		ft_free_elem_pile(pile, parser);
		pile->prev->value = POSITION_INST;
		return (1);
	}
	return (0);
}
