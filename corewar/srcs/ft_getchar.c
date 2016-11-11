/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:43 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:43 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

char	ft_getchar(const char *arene)
{
	unsigned char ret;

	ret = 0;
	if (*arene < 58)
		ret = (*(arene) - 48) * 16;
	else
		ret = (*(arene) - 55) * 16;
	if (*(arene + 1) < 58)
		ret += (*(arene + 1) - 48);
	else
		ret += (*(arene + 1) - 55);
	return ((char)ret);
}
