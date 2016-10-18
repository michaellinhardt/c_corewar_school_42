#ifndef FT_ASM_H
# define FT_ASM_H

#include "ft_struct_asm.h"

/*
** Recuperation des infos du (des) fichiers
*/
int			ft_open_file(char **argv);
int			ft_get_size_file(int fd);


/*
** Lexer
*/
t_token		*ft_new_token(t_lexer *lexer);
void		ft_init_lexer(t_lexer *lexer);
int			ft_lexer(t_lexer *lexer);


/*
**	Display
*/

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
int			ft_lexer_direct_label(t_lexer *lexer, t_token *token);
int			ft_lexer_register(t_lexer *lexer, t_token *token);
int			ft_lexer_endline(t_lexer *lexer, t_token *token);
int			ft_lexer_end(t_lexer *lexer, t_token *token);
#endif
