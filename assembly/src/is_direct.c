/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 23:01:41 by pba               #+#    #+#             */
/*   Updated: 2016/10/02 01:40:19 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				is_direct(char *str)
{
	int			i;

	if (str && str[0] == DIRECT_CHAR)
	{
		if (ft_isint(&str[i]))
			return (1);
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
