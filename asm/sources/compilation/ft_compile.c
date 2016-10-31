#include "libft.h"
#include "ft_asm.h"

int			ft_compile_register(t_parse_tree *tree, unsigned char *code)
{
	char	*registre;

	registre = tree->token->value;
	++registre;
	*code = *registre - 48;
	if (*(++registre))
		*code = (*registre - 48) + *code * 10;
	return (1);
}

int		ft_compile_direct(t_parse_tree *tree, unsigned char *code,
		int flag_dir)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;
	unsigned int size;

	nbr = ft_atoi(tree->token->value + 1);
	if (flag_dir)
	{
		nbr = (unsigned short)nbr;
		size = 2;
	}
	else
		size = 4;
	decal = (size - 1) * 8;
	i = 0;
	while (i < size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (size);
}

int			ft_compile_direct_label(t_parse_tree *tree, unsigned char *code,
		int	flag_dir)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;
	unsigned int size;
	
	nbr = tree->position;
	if (flag_dir)
	{
		nbr = (unsigned short)nbr;
		size = 2;
	}
	else
		size = 4;
	decal = (size - 1) * 8;
	i = 0;
	while (i < size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (size);
}

int			ft_compile_indirect(t_parse_tree *tree, unsigned char *code)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;
	unsigned int size;

	nbr = ft_atoi(tree->token->value);
	nbr = (unsigned short)nbr;
	size = 2;
	decal = (size - 1) * 8;
	i = 0;
	while (i < size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (size);
}

#include <stdlib.h>
int			ft_compile_instruction(t_parse_tree *tree, unsigned char **code,
		const t_instructions *inst, unsigned int size)
{
	int 	i;
	unsigned int	size_inst;
	unsigned char	code_inst[20];

	i = 0;
	size_inst = 0;
	ft_bzero(&code_inst, 20);
	code_inst[size_inst++] = tree->id_instruction;
//	ft_putendl(tree->token->value);
	if (inst[tree->id_instruction].flag_ocp)
		code_inst[size_inst++] = ft_set_oc_p(tree->id_instruction, tree);
	while (i < tree->nbr_fils)
	{
		if (tree->fils[i] && tree->fils[i]->token->token == REGISTER)
		{
			size_inst += ft_compile_register(tree->fils[i], code_inst + size_inst);
		}
		else if (tree->fils[i] && tree->fils[i]->token->token == DIRECT)
		{
			size_inst += ft_compile_direct(tree->fils[i], code_inst + size_inst,
					inst[tree->id_instruction].flag_size_ind);
		} 
		else if (tree->fils[i] && tree->fils[i]->token->token == DIRECT_LABEL)
		{
			size_inst += ft_compile_direct_label(tree->fils[i], code_inst
					+ size_inst, inst[tree->id_instruction].flag_size_ind);
		} 
		else if (tree->fils[i] && tree->fils[i]->token->token == INDIRECT)
		{
			size_inst += ft_compile_indirect(tree->fils[i], code_inst
					+ size_inst);
		} 
		else if (tree->fils[i] && tree->fils[i]->token->token == INDIRECT_LABEL)
		{
			size_inst += ft_compile_direct_label(tree->fils[i], code_inst
					+ size_inst, 1);
		} 
		++i;
	}
//	ft_print_memory(&code_inst, size_inst);
	if (!*code)
	{
		*code = ft_memalloc(sizeof(unsigned char) * size_inst);		
		ft_memcpy(*code, code_inst, size_inst);
	}
	else
	{
		*code  = realloc(*code, sizeof(unsigned char) *
				(size_inst + size));
		ft_memcpy(*code + size, code_inst, size_inst);
	}
	return (size_inst);
}

void			ft_compile_name(t_parse_tree *name, t_header *header)
{
	ft_memcpy(header->prog_name, name->fils[0]->token->value + 1,
			name->fils[0]->token->size -2);
}	

void			ft_compile_comment(t_parse_tree *name, t_header *header)
{
	ft_memcpy(header->comment, name->fils[0]->token->value + 1,
			name->fils[0]->token->size -2);
}


int			ft_compile_label(t_parse_tree *tree, unsigned char **code,
		const t_instructions *inst, unsigned int size)
{
	int i;

	i = 0;
	while ( i < tree->nbr_fils)
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
		i = 0;
		while (i < tree->nbr_fils)
		{
			if (tree->fils[i] &&  tree->fils[i]->token->token == ENDLINE)
				return (ft_compile(tree->fils[i], code, compile, size));
			else if (tree->fils[i] && tree->fils[i]->token->token == INSTRUCTION)
			{
				size += ft_compile_instruction(tree->fils[i], code,
						compile->inst, size);
			}
			else if (tree->fils[i] && tree->fils[i]->token->token == LABEL)
			{
				size = ft_compile_label(tree->fils[i], code, compile->inst, size);
			}
			else if (tree->fils[i] && tree->fils[i]->token->token == COMMAND_NAME)
			{
				ft_compile_name(tree->fils[i], &compile->header);
			}
			else if (tree->fils[i] && tree->fils[i]->token->token == COMMAND_COMMENT)
			{
				ft_compile_comment(tree->fils[i], &compile->header);
				// pase de size
			}
			++i;
		}
	}
	return (size);
}
