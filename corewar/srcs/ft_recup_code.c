/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:54 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:54 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void		ft_recup_code(t_dvm *vm, t_dargs *args)
{
	int		i;
	char	verif[1];
	ssize_t ret;

	i = 0;
	while (i < vm->nbr_players)
	{
		l1(1, "READ CODE", args[i].file);
		if ((ret = read(args[i].fd, vm->p[i].code, vm->p[i].header.prog_size))
				== -1)
			exit1(1, data(), "Pb de read fdp");
		if (ret != vm->p[i].header.prog_size)
			exit1(1, data(), "Batard pas la bonne taille");
		if ((ret = read(args[i].fd, verif, 1)) != 0)
			exit1(1, data(), "File overflow prog_size");
		vm->p[i].playing = 1;
		vm->last_live = i + 1;
		++i;
	}
}
