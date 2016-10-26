#include <stdlib.h>
#include "libft.h"
#include "ft_asm.h"

/*
** faire tableau de pointeurs sur fonctiosn comme shift et reduce
*/

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

int	ft_accept_label(t_parser *parser, t_pile_tree *pile)
{

	return (0);
}

int	ft_accept_name(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == MINI_NAME)
	{
		if (!pile->next && pile->next->value != ENDLINE)
		{
			ft_putendl("erreur mini name");
			return (-1);
		}
		ft_putendl("accept mini name");
		ft_add_leaf(pile->next->tree, pile->tree);
		pile->next->value = CMD_NAME;
		ft_free_elem_pile(pile, parser);
		return (SHIFT);
	}
	return (0);
}

int	ft_accept_comment(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == MINI_COMMENT)
	{
		ft_putendl("accept mini comment");
		if (!pile->next && pile->next->value != ENDLINE)
		{
			ft_putendl("erreur mini comment");
			return (-1);
		}
		pile->next->value = CMD_COMMENT;
		ft_add_leaf(pile->next->tree, pile->tree);
		ft_free_elem_pile(pile, parser);
		return (SHIFT);
	// add parent + free elem pile
	}
	return (0);
}

int	ft_accept_argument(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == ARG)
	{
		if (!pile->next || pile->next->value != ENDLINE)
		{
			ft_putendl("erreur accept argument");
			return (-1);
		}
		ft_putendl("accept last arg");
		pile->next->value = LAST_ARG;
		ft_add_leaf(pile->next->tree, pile->tree);
		ft_free_elem_pile(pile, parser);
		return (SHIFT);
	}
	return (0);
}

int	ft_accept_separator_char(t_parser *parser, t_pile_tree *pile)
{
	if (pile->value == SEPARATOR_CHAR)
	{
		if (!pile->next)
		{
			ft_putendl("erreur accept separator char");
			return (-1);
		}	
		if (pile->next->value == SEPARATOR_CHAR ||
				pile->next->value == ARG)
			return (0);

		if (pile->next->value == LAST_ARG)
		{
			ft_add_leaf(pile->next->tree, pile->tree);
			ft_free_elem_pile(pile, parser);
		}
		else
		{
			ft_putendl("touve l'erreur :)");
			return (-1);
		}
		return (SHIFT);
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
	if (pile->value == INST)
	{
		if (!pile->next)
			return (-1);
		if (pile->next->value == ARG || pile->next->value == SEPARATOR_CHAR)
			return (0);
		if (pile->next->value == LAST_ARG)
		{
			if (ft_verif_instruction(pile, pile->next,parser->inst))
			{
				ft_putendl("accept INSTRUCTION");
				ft_complete_instruction(pile->tree, pile->next->tree);
				pile->value = CPL_INST;
				ft_free_pointeur_tab_fils(pile->next->tree);
				ft_free_elem_pile(pile->next, parser);
			}
			else
			{
				ft_putendl("erreur accept instruction");
				return (-1);
			}
			/*
			ft_add_leaf(pile->next->tree, pile->tree);
			ft_free_elem_pile(pile, parser);
			*/
			return (1);
		}
		else
		{
			ft_putendl("erreur accept INSTRUCTION");
			return (-1);
		}
	}
	return (0);
}
