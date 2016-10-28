#include "libft.h"
#include "ft_asm.h"

// renvoi de unsigned char -> useless
/*
unsigned char	*ft_compile_name(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{

	ft_memcpy(compile->header.prog_name, tree->fils[0]->token->value,
			ft_strlen(tree->fils[0]->token->value));
	return (0);
}
unsigned char	*ft_compile_comment(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{

	ft_memcpy(compile->header.comment, tree->fils[0]->token->value,
			ft_strlen(tree->fils[0]->token->value));
	return (0);
}
// useless
unsigned char	*ft_compile_string(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	ft_putendl(tree->token->value);
	return (0);
}

unsigned char	*ft_compile_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	unsigned int i;


	ft_putendl(tree->token->value);
	i = 0;
	while (i < tree->nbr_fils)
	{
		ft_compile_instruction(tree->fils[i], code, compile);
		++i;
	}

	return (0);
}

unsigned char	*ft_compile_endline(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	int i;

	if (tree)
	{
		i = 0;
		while (i < tree->nbr_fils)
		{
			compile->f_compile[tree->fils[i]->token->token](tree->fils[i], code, compile); 
			++i;
		}
	}
	return (0);
}

unsigned char	*ft_compile_indirect(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	compile->size = 2;
	ft_putendl(tree->token->value);
	return (0);
}

#include <stdlib.h>
unsigned char	*ft_compile_instruction(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	int				i;
	unsigned char	inst[20];
	unsigned int	size;
	unsigned char	code_arg[4];

	size = 0;
	i = 0;
	ft_bzero(&inst, 20);
	inst[size++] = tree->id_instruction;
	compile->actual_inst = &compile->inst[tree->id_instruction];
	ft_putendl(tree->token->value);
	if (compile->actual_inst->flag_ocp)
		inst[size++] = ft_set_oc_p(tree->id_instruction, tree);
	while (i < tree->nbr_fils)
	{
		compile->f_compile[tree->fils[i]->token->token]
			(tree->fils[i], code_arg, compile); 
		ft_memcpy(inst + size, code_arg , compile->size);
		size += compile->size;
		++i;
	}



	ft_print_memory(&inst, size);
	if (!compile->code)
	{
		compile->code = ft_memalloc(sizeof(unsigned char) * size);		
		ft_memcpy(compile->code, inst, size);
	}
	else
	{
		compile->code  = realloc(compile->code, sizeof(unsigned char) *
				(size + compile->total_size));
		ft_memcpy(compile->code + compile->total_size, inst, size);
	}
	compile->total_size += size; // on s'en balle les couilles je crois
	return (0);
}
unsigned char	*ft_compile_indirect_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{

	compile->size = 2;
	ft_putendl(tree->token->value);
	return (0);
}
unsigned char	*ft_compile_direct(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;

	nbr = ft_atoi(tree->token->value + 1);
	if (compile->actual_inst->flag_size_ind)
	{
		nbr = (unsigned short)nbr;
		compile->size = 2;
	}
	else
		compile->size = 4;
	i = 0;
	decal = (compile->size - 1) * 8;
	while (i < compile->size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (0);
}
unsigned char	*ft_compile_direct_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	if (compile->actual_inst->flag_size_ind)
		compile->size = 2;
	else
		compile->size = 4;
	ft_putnbr(tree->poids);
//	ft_putendl(tree->token->value);
	return (0);
}

*/
/*
int			ft_compile(t_parse_tree *tree, t_compile *compile, unsigned char *code)
{
	int i;

	if (tree)
	{
		i = 0;
		while (i < tree->nbr_fils)
		{
			compile->f_compile[tree->fils[i]->token->token](tree->fils[i], code, compile); 
			++i;
		}
	}
	return (1);
}
*/

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
		t_instructions *inst, unsigned int size)
{
	unsigned int 	i;
	unsigned int	size_inst;
	unsigned char	code_inst[20];

	i = 0;
	size_inst = 0;
	ft_bzero(&code_inst, 20);
	code_inst[size_inst++] = tree->id_instruction;
	ft_putendl(tree->token->value);
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
	ft_print_memory(&code_inst, size_inst);
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

int			ft_compile(t_parse_tree *tree, unsigned char **code,
		t_instructions *inst, unsigned int size)
{
	unsigned int i;

	if (tree)
	{
		i = 0;
		while (i < tree->nbr_fils)
		{
			if (tree->fils[i] &&  tree->fils[i]->token->token == ENDLINE)
				return (size + ft_compile(tree->fils[i], code, inst, size));
			else if (tree->fils[i] && tree->fils[i]->token->token == INSTRUCTION)
			{
				size += ft_compile_instruction(tree->fils[i], code, inst, size);
			}
			else if (tree->fils[i] && tree->fils[i]->token->token == LABEL)
			{
			}
			else if (tree->fils[i] && tree->fils[i]->token->token == COMMAND_NAME)
			{
				// pas de size
			}
			else if (tree->fils[i] && tree->fils[i]->token->token == COMMAND_NAME)
			{
				// pase de size
			}
			++i;
		}
	}
	return (size);
}
