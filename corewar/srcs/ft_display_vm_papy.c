/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_vm_papy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:42 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:42 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	ft_display_vm_papy(t_dvm *vm)
{
	int		i;

	i = 0;
	while (i < SIZE_CHAR_ARENE)
	{
		if (!(i % 128))
			ft_put_hex_compteur(i / 2);
		if (*(vm->arene + i) >= 65)
			ft_putchar(*(vm->arene + i) + 32);
		else
			ft_putchar(*(vm->arene + i));
		++i;
		if (!(i % 2))
			ft_putchar(' ');
		if (!(i % 128))
			ft_putchar('\n');
	}
}
