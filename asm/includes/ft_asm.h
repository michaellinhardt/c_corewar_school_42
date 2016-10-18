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
t_token		*ft_init_token(t_token *token);
void		ft_init_lexer(t_lexer *lexer);
void		ft_lexer(t_lexer *lexer);


/*
**			Tokenisation
*/
int			ft_lexer_name();
#endif
