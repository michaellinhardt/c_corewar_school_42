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

// le truc final
//
struct				s_parse_tree
{
	t_token			*token;
	int				nbr_fils;
	int				term;
	int				rule;
	t_parse_tree	**fils;
	// le pointeur sur fonction pour l'action a effectuer
};

typedef struct s_pile_tree t_pile_tree;

enum	e_value {NO_VALUE, MINI_NAME, CMD_NAME, MINI_COMMENT, CMD_COMMENT, HEADER};

struct				s_pile_tree
{
	int				value;
	t_parse_tree	*tree;
	t_pile_tree		*next;
	t_pile_tree		*prev;
};

typedef struct		s_memory t_memory;

struct					s_memory
{
	unsigned int		name:1;
	unsigned int		ccomment:1;	
	unsigned int		header:1;
};

struct					s_parser
{
		char			*code;
		int				size;
		int				size_fonction;
		t_memory		memory;
		t_token			*focus;
		t_parse_tree	*tree_header;
		t_parse_tree	*tree_code;
		t_pile_tree		*debut_pile;
		t_pile_tree		*end_pile;
		t_pile_tree		*focus_pile;
};
#endif
