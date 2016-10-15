/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_indirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 23:02:33 by pba               #+#    #+#             */
/*   Updated: 2016/10/02 01:40:44 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					is_indirect(char *str)
{
	int				i;

	if (str && ft_isint(str))
		return (1);
	if (str && str[0] == LABEL_CHAR)
	{
		i = 1;
		while (str[i])
		{
			if (!ft_charchr(LABEL_CHARS, str[i]))
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}
