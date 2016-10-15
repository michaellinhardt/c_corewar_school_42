/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:53:55 by pba               #+#    #+#             */
/*   Updated: 2016/10/02 01:40:54 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				is_label(char *str)
{
	int			i;
	int			j;
	int			wrong;

	i = 0
	if (str && str[i++] == LABEL_CHAR)
	{
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
