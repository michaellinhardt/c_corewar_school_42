#include "libft.h"
#include "ft_asm.h"

// renvoi de unsigned char -> useless
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
unsigned char	*ft_compile_string(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	ft_putendl(tree->token->value);
	return (0);
}

unsigned char	*ft_compile_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	ft_putendl(tree->token->value);

	return (0);
}
unsigned char	*ft_compile_register(t_parse_tree *tree, unsigned char *code,
		t_compile *compile)
{
	char	*registre;
	compile->size = 1;

	registre = tree->token->value;
	++registre;
	*code = *registre - 48;
	if (*(++registre))
		*code = (*registre - 48) + *code * 10;
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
			ft_putendl("lol");
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
	compile->total_size += size;
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
	ft_putnbr(nbr);
	ft_putchar('\n');
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
	ft_putendl(tree->token->value);
	return (0);
}

int			ft_compile(t_parse_tree *tree, t_compile *compile, unsigned char *code)
{
	int i;

	if (tree)
	{
		i = 0;
		while (i < tree->nbr_fils)
		{
			ft_putendl("lol");
			compile->f_compile[tree->fils[i]->token->token](tree->fils[i], code, compile); 
			++i;
		}
	}
	return (1);
}
