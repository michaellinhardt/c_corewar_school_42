/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_instructions_end.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:44 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:44 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	ft_init_instructions_types_arg_deux(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = T_REG;
	inst[i++].types[2] = T_DIR | T_REG;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = 0;
	inst[i++].types[2] = T_REG;
}

void	ft_init_instructions_cycles(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].cycles = 10;
	inst[i++].cycles = 5;
	inst[i++].cycles = 5;
	inst[i++].cycles = 10;
	inst[i++].cycles = 10;
	inst[i++].cycles = 6;
	inst[i++].cycles = 6;
	inst[i++].cycles = 6;
	inst[i++].cycles = 20;
	inst[i++].cycles = 25;
	inst[i++].cycles = 25;
	inst[i++].cycles = 800;
	inst[i++].cycles = 10;
	inst[i++].cycles = 50;
	inst[i++].cycles = 1000;
	inst[i++].cycles = 2;
}
