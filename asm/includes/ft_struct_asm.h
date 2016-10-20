#ifndef FT_STRUCT_ASM_H
# define FT_STRUCT_ASM_H
# include "op.h"

# define DB_QUOTES -1
enum	e_token{
	NONE,
	COMMAND_NAME, 
	COMMAND_COMMENT,
	COMMENT,
	STRING,
	WHITESPACE,
	SEPARATOR,
	LABEL,
	REGISTER,
	INSTRUCTION,
	DIRECT_LABEL,
	INDIRECT_LABEL,
	DIRECT,
	INDIRECT,
	ENDLINE,
	END,
	NBR_TOKEN
};	

enum	e_sate {
	PRETRE,
		DEBUT,
		SHIFT,
		REDUCE
};

typedef struct s_token t_token;
typedef struct s_lexer t_lexer;
typedef struct s_parser t_parser;
typedef struct s_parse_tree t_parse_tree;

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
	int				y;
	char			*line;
	char			*focus;
	int				size;
	int				fd; // fd du fichier
	int				(*f_tokens[NBR_TOKEN])(t_lexer *lexer, t_token *token);
};

struct				s_parse_tree
{
	t_token			*token;
	int				nbr_fils;
	t_parse_tree	**fils;
	// le pointeur sur fonction pour l'action a effectuer
};

struct					s_parser
{
		char			*code;
		int				size;
		int				size_fonction;
		t_token			*focus_shft;
		t_token			*focus_reduce;
		t_parse_tree	*begin;
		t_parse_tree	*actual;
};
#endif
