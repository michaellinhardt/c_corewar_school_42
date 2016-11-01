#ifndef FT_STRUCT_ASM_H
# define FT_STRUCT_ASM_H
# include "op.h"
# define NBR_REDUCE 8
# define NBR_SHIFT 16
# define LEXER_STRING -1
# define LEXER_INCONNU -2
# define PARSER_INSTRUCTION_WRONG -1
# define PARSER_INSTRUCTION_NBR -2
# define NBR_ACCEPT 11
# define PARSER_INSTRUCTION_REGISTRE -3
# define PARSER_ARG_WRONG -4
# define RED "\033[0;31m"
# define NEUTRE "\033[0;m"

enum				e_token{
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

enum				e_value	{NO_VALUE,
	MINI_NAME,
	CMD_NAME,
	MINI_COMMENT,
	CMD_COMMENT,
	HEADER,
	ARG,
	INST,
	FIN_LINE,
	LAST_ARG,
	CPL_INST,
	POSITION,
	POSITION_INST,
	VIRGULE,
	CODE_FIN,
	FIN};

enum				e_action {ERREUR,
	SHIFT,
	REDUCE,
	ACCEPT,
	CODE_ACCEPT};

typedef struct s_pile_tree		t_pile_tree;
typedef struct s_instructions	t_instructions;
typedef struct s_token			t_token;
typedef struct s_lexer			t_lexer;
typedef struct s_parser			t_parser;
typedef struct s_parse_tree		t_parse_tree;
typedef struct s_compile		t_compile;

struct				s_instructions
{
	int				id;
	char			name[6];
	short			nbr_args;
	t_arg_type		types[MAX_ARGS_NUMBER];
	int				flag_ocp;
	int				flag_size_ind;
};

struct				s_compile
{
	t_header		header;
	unsigned char	*code;
	unsigned int	size;
	unsigned int	total_size;
	t_instructions	inst[17];
	t_instructions	*actual_inst;
	int				flag_size_ind;
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
	int				head;
	int				offset;
	int				size_line;
	unsigned int	y;
	unsigned int	x;
	char			*line;
	char			*focus;
	char			*name;
	int				size;
	int				fd;
	int				(*f_tokens[NBR_TOKEN])(t_lexer *lexer, t_token *token);
};

struct				s_parse_tree
{
	t_token			*token;
	int				nbr_fils;
	int				id_instruction;
	int				poids;
	int				position;
	t_parse_tree	**fils;
};

struct				s_pile_tree
{
	int				value;
	t_parse_tree	*tree;
	t_pile_tree		*next;
	t_pile_tree		*prev;
};

struct				s_parser
{
	int				size;
	int				size_fonction;
	int				(*f_reduce[NBR_REDUCE])(t_parser *parser,
			t_pile_tree *pile);
	int				(*f_shift[NBR_SHIFT])(t_parser *parser);
	int				(*f_accept[NBR_ACCEPT])(t_parser *parser,
			t_pile_tree *tree);
	t_instructions	inst[17];
	t_token			*focus;
	t_pile_tree		*debut_pile;
	t_pile_tree		*end_pile;
	t_pile_tree		*focus_pile;
};

#endif
