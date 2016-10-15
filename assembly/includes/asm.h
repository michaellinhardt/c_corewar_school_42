/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 08:31:03 by pba               #+#    #+#             */
/*   Updated: 2016/10/01 16:36:39 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef enum kind {NAME, COMMENT, LABEL, OPCODE, REGISTER, DIRECT, INDIRECT}
	e_kind;
typedef struct		s_token
{
	enum kind		kind;
	int				value;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;
typedef struct		s_tlist
{
	struct s_token	*head;
	struct s_token	*last;
	int				size;
}					t_tlist;
t_token				*token_new(enum kind, int value);
t_tlist				*list_new();
t_tlist				*list_append(t_tlist *list, enum kind, int value);
void				list_display(t_tlist *list);
int					is_topcomment(char *str);
int					is_comment(char *str);
int					is_direct(char *str);
int					is_indirect(char *str);
t_tlist				**lexer(int fd);
t_tlist				*tokenize(char *str);

#endif
