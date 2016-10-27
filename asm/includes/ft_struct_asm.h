#ifndef FT_STRUCT_ASM_H
# define FT_STRUCT_ASM_H
# include "op.h"

# define NBR_REDUCE 7
# define NBR_SHIFT 14
# define NBR_ACCEPT 8
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
	INDIRECT,
	INSTRUCTION,
	DIRECT_LABEL,
	INDIRECT_LABEL,
	DIRECT,
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
	int				id_instruction;
//	int				term;
//	int				rule;
	t_parse_tree	**fils;
	// le pointeur sur fonction pour l'action a effectuer
};

typedef struct s_pile_tree t_pile_tree;
typedef struct s_instructions t_instructions;

enum	e_value {NO_VALUE, MINI_NAME, CMD_NAME, MINI_COMMENT, CMD_COMMENT, HEADER,
				INST, ARG, VIRGULE, LAST_ARG, CPL_INST};
enum	e_action {ERREUR, SHIFT, REDUCE, ACCEPT};

struct				s_pile_tree
{
	int				value;
//	t_instructions	*inst;
	t_parse_tree	*tree;
	t_pile_tree		*next;
	t_pile_tree		*prev;
};


typedef char            t_arg_type;
typedef struct s_dvm    t_dvm;
typedef struct s_proc   t_proc;

struct          s_instructions
{
	int						id;
	char					name[6];
	short					nbr_args;
	t_arg_type				types[MAX_ARGS_NUMBER];
	int						flag_ocp;
	int						flag_size_ind;
};

/*
typedef struct		s_memory t_memory;

struct					s_memory
{
	unsigned int		name:1;
	unsigned int		ccomment:1;	
	unsigned int		header:1;
	unsigned int		arg:1;
};

*/

struct					s_parser
{
	char			*code;
	int				size;
	int				size_fonction;
	int				(*f_reduce[NBR_REDUCE])(t_parser *parser, t_pile_tree *pile);
	int				(*f_shift[NBR_SHIFT])(t_parser *parser);
	int				(*f_accept[NBR_ACCEPT])(t_parser *parser, t_pile_tree *tree);
	t_instructions	inst[17];
//	t_memory		memory;
	t_token			*focus;
	t_parse_tree	*tree_header;
	t_parse_tree	*tree_code;
	t_pile_tree		*debut_pile;
	t_pile_tree		*end_pile;
	t_pile_tree		*focus_pile;
};

#endif
