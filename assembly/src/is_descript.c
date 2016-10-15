/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_descript.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:02:52 by pba               #+#    #+#             */
/*   Updated: 2016/10/08 17:47:01 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					is_descript(char *str)
{
	int				len;
	char			*terms[3];

	ft_memset((void *)terms, 0, sizeof(char *) * 3);
	terms[0] = str;
	while (str && str[i])
	{
		if (str[i] == ' ')
		{
			str[i] = '\0';
			terms[1] = &str[i + 1];
			break ;
		}
		++i;
	}
	if (terms[0] && terms[1] && (len = ft_strlen(terms[1])) > 0)
	{
		if (ft_strequ(terms[0], COMMENT_CMD_STRING) && terms[1][0] == '"'
				&& terms[1][len - 1] == '"')
			return (1);
	}
	return (0);
}
