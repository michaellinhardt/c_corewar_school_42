#ifndef FT_ASM_H
# define FT_ASM_H

#include "ft_struct_asm.h"

/*
** Recuperation des infos du (des) fichiers
*/
int			ft_open_file(char **argv);
int			ft_get_size_file(int fd);
char		*ft_get_line(int fd, t_lexer *lexer);


/*
** Lexer
*/
t_token		*ft_new_token(t_lexer *lexer);
void		ft_init_lexer(t_lexer *lexer);
int			ft_lexer(t_lexer *lexer);
void		ft_get_value(t_lexer *lexer, t_token *token, int size);


void		ft_free_tokens(t_token *token);
void		ft_lexer_error(t_lexer *lexer, int erreur);

/*
**	Display
*/
void		ft_display_tokenisation(t_token *token);
void		ft_display_type_token(int token);
void		ft_display_parse_tree(t_parse_tree *tree);

/*
**			Tokenisation
*/
int			ft_lexer_command_name(t_lexer *lexer, t_token *token);
int			ft_lexer_command_comment(t_lexer *lexer, t_token *token);
int			ft_lexer_comment(t_lexer *lexer, t_token *token);
int			ft_lexer_string(t_lexer *lexer, t_token *token);
int			ft_lexer_whitespace(t_lexer *lexer, t_token *token);
int			ft_lexer_separator(t_lexer *lexer, t_token *token);
int			ft_lexer_label(t_lexer *lexer, t_token *token);
int			ft_lexer_direct(t_lexer *lexer, t_token *token);
int			ft_lexer_instruction(t_lexer *lexer, t_token *token);
int			ft_lexer_indirect(t_lexer *lexer, t_token *token);
int			ft_lexer_indirect_label(t_lexer *lexer, t_token *token);
int			ft_lexer_direct_label(t_lexer *lexer, t_token *token);
int			ft_lexer_register(t_lexer *lexer, t_token *token);
int			ft_lexer_endline(t_lexer *lexer, t_token *token);
int			ft_lexer_end(t_lexer *lexer, t_token *token);

/*
**	Parser
*/

int			ft_parser(t_token *token, t_parser *parser);


int			ft_parser_shift(t_parser *parser);
int			ft_parser_reduce(t_parser *parser);

/*
** Parse tree
*/

void		ft_add_node(t_parse_tree *tree, t_parse_tree *leaf);
t_parse_tree *ft_create_leaf(t_token *token);
#endif
