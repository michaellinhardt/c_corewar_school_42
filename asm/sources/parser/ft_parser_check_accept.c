#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

/*
** faire tableau de pointeurs sur fonctiosn comme shift et reduce
*/

/*
int	ft_accept_header(t_parser *parser, t_pile_tree *pile)
{
	t_parse_tree *tree;

	if (pile->next && (pile->value == CMD_NAME || pile->value == CMD_COMMENT))
	{
		if (pile->value == CMD_NAME)
		{
			if (!pile->next || pile->next->value != CMD_COMMENT)
				return (0);
			ft_putendl("reduction  header");
			ft_add_leaf(pile->tree, pile->next->tree->fils[0]);
			tree = pile->next->tree;
			pile->next->tree = pile->next->tree->fils[0];
			free (tree->fils);
			free (tree);
			ft_free_elem_pile(pile->next, parser);
			return (1);
		}
		else if (pile->value == CMD_COMMENT)
		{
			if (!pile->next || pile->next->value != CMD_NAME)
				return (0);
			ft_putendl("reduction  header");
			ft_add_leaf(pile->next->tree, pile->tree->fils[0]);
			tree = pile->tree;
			pile->tree = pile->tree->fils[0];
			free (tree->fils);
			free (tree);
			ft_free_elem_pile(pile, parser);
			return (1);
		}
	}
	return (0);
}
*/

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
				ft_putendl("erreur accept header");
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
				ft_putendl("erreur accept header");
				return (-1);
			}
		}
	}
	return (0);
}

int	ft_accept_label(t_parser *parser, t_pile_tree *pile)
{

	return (0);
}

int	ft_accept_name(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == ENDLINE)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur mini name");
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
	if (pile->value == ENDLINE)
	{

		if (!pile->prev)
		{
			ft_putendl("erreur mini comment");
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
	if (pile->value == ENDLINE)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept argument");
			return (-1);
		}
		if (pile->prev->value == ARG)
		{
			ft_putendl("accept last arg");
			pile->value = LAST_ARG;
			ft_add_leaf(pile->tree, pile->prev->tree);
			ft_free_elem_pile(pile->prev, parser);
			return (1);
		}
	}
	return (0);
}

int	ft_accept_separator_char(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == LAST_ARG)
	{
		if (!pile->prev)
		{
			ft_putendl("erreur accept separator char");
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
			ft_putendl("erreur accept separator char");
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
			}
			return (0);
		}
		else
		{
			ft_putendl("erreur accept instruction");
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
// concatete +sieurs instrctuions a l'affile
int			ft_accept_end_inst(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == FIN_INST)
	{
		if (pile->prev->value == CPL_INST)
		{
			ft_add_leaf(pile->prev->tree, pile->tree->fils[0]);
			free(pile->tree->fils);
			free(pile->tree);
			ft_free_elem_pile(pile, parser);
			ft_putendl("accept instruction multiples");
			return (-1);
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
			ft_putendl("erreur accept end");
			return (-1);
		}
	}
	return (0);
}
