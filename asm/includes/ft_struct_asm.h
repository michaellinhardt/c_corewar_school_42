#ifndef FT_STRUCT_ASM_H
# define FT_STRUCT_ASM_H
# include "op.h"

enum	e_token{COMMAND_NAME, 
	COMMAND_COMMENT,
	COMMENT,
	STRING,
	WHITESPACE,
	SEPARATOR,
	LABEL,
	DIRECT,
	INSTRUCTION,
	INDIRECT,
	DIRECT_LABEL,
	REGISTER,
	ENDLINE,
	END,
	NBR_TOKEN
};	

typedef struct s_token t_token;
typedef struct s_lexer t_lexer;

struct				s_token
{
	unsigned int	token;
	unsigned int	size;
	char			*value;
	t_token			*next;
};

struct				s_lexer
{
	t_token			*begin;
	t_token			*end;
	int				head; // l'endroir tou on est dans le fichier
	int				offset; // le decalage dans la fonction
	int				size_line;
	char			*line;
	char			*focus;
	char			labels[38];
	int				size;
	int				fd; // fd du fichier
	int				(*f_tokens[NBR_TOKEN])(t_lexer *lexer, t_token *token);
};
#endif
