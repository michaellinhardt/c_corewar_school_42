#include "libft.h"
#include "ft_asm.h"
#include <stdlib.h>

static unsigned int	ft_malloc_code(unsigned char **code, unsigned int size_inst,
		unsigned int size, unsigned char *code_inst)
{
	if (!*code)
	{
		*code = ft_memalloc(sizeof(unsigned char) * size_inst);
		ft_memcpy(*code, code_inst, size_inst);
	}
	else
	{
		*code = realloc(*code, sizeof(unsigned char) *
				(size_inst + size));
		ft_memcpy(*code + size, code_inst, size_inst);
	}
	return (size_inst);
}

static void			ft_init_instruction(int *i, unsigned int *size_inst,
		unsigned char *code_inst, t_parse_tree *tree)
{
	(void)tree;
	*i = -1;
	*size_inst = 0;
	ft_bzero(code_inst, 20);
}

int					ft_compile_instruction(t_parse_tree *tree,
		unsigned char **code, const t_instructions *inst, unsigned int size)
{
	int				i;
	unsigned int	s;
	unsigned char	code_inst[20];

	ft_init_instruction(&i, &s, code_inst, tree);
	code_inst[s++] = tree->id_instruction;
	if (inst[tree->id_instruction].flag_ocp)
		code_inst[s++] = ft_set_oc_p(tree->id_instruction, tree);
	while (++i < tree->nbr_fils)
	{
		if (tree->fils[i] && tree->fils[i]->token->token == REGISTER)
			s += ft_compile_register(tree->fils[i], code_inst + s);
		else if (tree->fils[i] && tree->fils[i]->token->token == DIRECT)
			s += ft_compile_direct(tree->fils[i], code_inst + s,
					inst[tree->id_instruction].flag_size_ind);
		else if (tree->fils[i] && tree->fils[i]->token->token == DIRECT_LABEL)
			s += ft_compile_direct_label(tree->fils[i], code_inst
					+ s, inst[tree->id_instruction].flag_size_ind);
		else if (tree->fils[i] && tree->fils[i]->token->token == INDIRECT)
			s += ft_compile_indirect(tree->fils[i], code_inst
					+ s);
		else if (tree->fils[i] && tree->fils[i]->token->token == INDIRECT_LABEL)
			s += ft_compile_direct_label(tree->fils[i], code_inst + s, 1);
	}
	return (ft_malloc_code(code, s, size, code_inst));
}
