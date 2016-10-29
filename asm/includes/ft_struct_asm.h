#ifndef FT_STRUCT_ASM_H
# define FT_STRUCT_ASM_H
# include "op.h"

# define NBR_REDUCE 8
# define NBR_SHIFT 16
# define NBR_ACCEPT 11


#define LEXER_STRING -1
#define LEXER_INCONNU -2
# define RED "\033[0;31m"
# define NEUTRE "\033[0;m"
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


typedef struct s_pile_tree t_pile_tree;
typedef struct s_instructions t_instructions;
typedef struct s_token t_token;
typedef struct s_lexer t_lexer;
typedef struct s_parser t_parser;
typedef struct s_parse_tree t_parse_tree;
typedef struct s_compile t_compile;
/*
typedef unsigned char * (*f_compilation[ENDLINE])(t_parse_tree *tree, unsigned 
		char *code, t_compile *compile);
		*/
struct          s_instructions
{
	int						id;
	char					name[6];
	short					nbr_args;
	t_arg_type				types[MAX_ARGS_NUMBER];
	int						flag_ocp;
	int						flag_size_ind;
};




struct	s_compile
{
	t_header		header;
	unsigned char	*code;
	unsigned int	size;
	unsigned int	total_size;
	t_instructions	inst[17];
	t_instructions	*actual_inst;
	int				flag_size_ind; // c'est pas direct ?
	unsigned char	*(*f_compile[ENDLINE + 1])(t_parse_tree *tree, unsigned char
			*code, t_compile *compile);
};

struct				s_token
{
	unsigned int	token;
	unsigned int	size;
	char			*value;
	unsigned int	y;
	unsigned int	x;
	t_token			*next;
};

struct				s_lexer
{
	t_token			*begin;
	t_token			*end;
	int				head; // l'endroir tou on est dans le fichier
	int				offset; // le decalage dans la fonction
	int				size_line;
	unsigned int	y;
	unsigned int 	x;
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
	int				poids; // le poids du bordel
	int				position;
	t_parse_tree	**fils;
	// le pointeur sur fonction pour l'action a effectuer
};


enum	e_value {NO_VALUE, MINI_NAME, CMD_NAME, MINI_COMMENT, CMD_COMMENT, HEADER,
				INST, ARG, VIRGULE, LAST_ARG, CPL_INST, FIN_INST, POSITION,
				FIN_LINE, FIN_LABEL,
				FIN};

enum	e_action {ERREUR, SHIFT, REDUCE, ACCEPT, CODE_ACCEPT};

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
	t_parse_tree	*tree_header; // useless
	t_parse_tree	*tree_code; // aussi
	t_pile_tree		*debut_pile;
	t_pile_tree		*end_pile;
	t_pile_tree		*focus_pile;
};

#endif
