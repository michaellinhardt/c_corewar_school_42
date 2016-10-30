#include "libft.h"
#include "ft_asm.h"

static void	ft_display_poids(t_parse_tree *tree)
{
	unsigned int i;

	i = 0;
	if (tree->token->token == INSTRUCTION)
		ft_printf("inst : %s, poids : %d\n", tree->token->value, tree->poids);
	else if (tree->token->token == LABEL)
		ft_printf("label %s position : %d\n", tree->token->value, tree->position);
	while (i < tree->nbr_fils)
	{
		ft_display_poids(tree->fils[i]);
		++i;
	}
}

void	ft_create_header(t_header *header, t_token *token)
{
	t_token			*ts;
	unsigned int	i;

	i = -1;
	ts = token;
	while (token && token->token != COMMAND_NAME)
		token = token->next;
	token = token->next->next;
	if (token->token == STRING)
	{
		while (++i < token->size && i < PROG_NAME_LENGTH + 1)
			header->prog_name[i] = token->value[i];
	}
	i = -1;
	token = ts;
	while (token && token->token != COMMAND_COMMENT)
		token = token->next;
	token = token->next->next;
	if (token->token == STRING)
	{
		while (++i < token->size && i < COMMENT_LENGTH + 1)
			header->comment[i] = token->value[i];
	}
	header->magic = COREWAR_EXEC_MAGIC;
}

int		ft_compilation(t_parse_tree *tree, t_parser *parser, t_token *token)
{
	//	typedef unsigned char	(*f_compilation[ENDLINE])(t_parse_tree *tree);
	t_compile compile;
	unsigned int poids;
	unsigned int size;

	poids = 0;
	compile.code = 0;
	compile.total_size = 0;
	ft_init_compilation(&compile);
	ft_putendl("test compilation");
	ft_bzero(&compile.header, sizeof(t_header));
	ft_create_header(&compile.header, token);
	ft_init_instructions(compile.inst);
	ft_putendl("---------------");
	size = ft_calcul_poids(tree, compile.inst, poids);

	if (ft_search_label(tree, tree))
	{
			ft_putendl("erreur compilation label search");
	}

	ft_putendl("display poids");
	ft_putendl("---------------");
	ft_putnbr(size);
	ft_display_poids(tree);
	ft_putendl("---------------");

	unsigned char	*code;

	code = 0;
	size = ft_compile(tree, &code, compile.inst, 0);
	compile.header.prog_size = size;
	ft_putnbr(size);

	ft_putendl("Resultat :");
	ft_printf("Magic :%#x\nname header :%s\n", compile.header.magic, compile.header.prog_name);
	ft_printf("comment header :%s\nSize prog :%d\n", compile.header.comment, compile.header.prog_size);
	ft_putendl("code ");
	ft_print_memory(code, size);
	return (1);
//	ft_print_memory(compile.code, compile.total_size);
}
