#include "libft.h"
#include "ft_asm.h"

void		ft_compile_name(t_parse_tree *name, t_header *header)
{
	ft_memcpy(header->prog_name, name->fils[0]->token->value + 1,
			name->fils[0]->token->size - 2);
}

void		ft_compile_comment(t_parse_tree *name, t_header *header)
{
	ft_memcpy(header->comment, name->fils[0]->token->value + 1,
			name->fils[0]->token->size - 2);
}

int			ft_compile_label(t_parse_tree *tree, unsigned char **code,
		const t_instructions *inst, unsigned int size)
{
	int i;

	i = 0;
	while (i < tree->nbr_fils)
	{
		size += ft_compile_instruction(tree->fils[i], code, inst, size);
		++i;
	}
	return (size);
}

int			ft_compile(t_parse_tree *tree, unsigned char **code,
		t_compile *compile, unsigned int size)
{
	int i;

	if (tree)
	{
		i = -1;
		while (++i < tree->nbr_fils)
		{
			if (tree->fils[i] && tree->fils[i]->token->token == ENDLINE)
				return (ft_compile(tree->fils[i], code, compile, size));
			else if (tree->fils[i] && tree->fils[i]->token->token
					== INSTRUCTION)
				size += ft_compile_instruction(tree->fils[i], code,
						compile->inst, size);
			else if (tree->fils[i] && tree->fils[i]->token->token == LABEL)
				size = ft_compile_label(tree->fils[i], code, compile->inst,
						size);
			else if (tree->fils[i] && tree->fils[i]->token->token
					== COMMAND_NAME)
				ft_compile_name(tree->fils[i], &compile->header);
			else if (tree->fils[i] && tree->fils[i]->token->token
					== COMMAND_COMMENT)
				ft_compile_comment(tree->fils[i], &compile->header);
		}
	}
	return (size);
}
