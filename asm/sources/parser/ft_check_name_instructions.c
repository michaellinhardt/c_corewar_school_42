/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:44 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:44 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "libft.h"

/*
**			Retourne l'id de l'instruction si ok
*/

int			ft_check_name_instructions(char *instruction, t_instructions *inst)
{
	int i;

	i = 1;
	while (i < NBR_INST)
	{
		if (!ft_strcmp(instruction, inst[i].name))
			return (i);
		++i;
	}
	return (0);
}
