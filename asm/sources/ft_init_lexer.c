#include "libft.h"
#include "ft_asm.h"

t_token		*ft_new_token(t_lexer *lexer)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_lexer))))
		return (0);
	if (lexer->end)
	{
		lexer->end->next = new;
		lexer->end = new;
	}
	else
	{
		lexer->begin = new;
		lexer->end = new;
	}
	return (new);
}


void		ft_init_lexer(t_lexer *lexer)
{
	lexer->f_tokens[COMMAND_NAME] = ft_lexer_command_name;
	lexer->f_tokens[COMMAND_COMMENT] = ft_lexer_command_comment;
	lexer->f_tokens[COMMENT] = ft_lexer_comment;
	lexer->f_tokens[STRING] = ft_lexer_string;
	lexer->f_tokens[WHITESPACE] = ft_lexer_whitespace;
	lexer->f_tokens[SEPARATOR] = ft_lexer_separator;
	lexer->f_tokens[LABEL] = ft_lexer_label;
	lexer->f_tokens[DIRECT] = ft_lexer_direct;
	lexer->f_tokens[INSTRUCTION] = ft_lexer_instruction;
	lexer->f_tokens[INDIRECT] = ft_lexer_indirect;
	lexer->f_tokens[DIRECT_LABEL] = ft_lexer_direct_label;
	lexer->f_tokens[REGISTER] = ft_lexer_register;
	lexer->f_tokens[ENDLINE] = ft_lexer_endline;
	lexer->f_tokens[END] = ft_lexer_end;
	lexer->f_tokens[INDIRECT_LABEL] = ft_lexer_indirect_label;
}
