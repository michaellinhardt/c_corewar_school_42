/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_instructions_end.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:22 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:22 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

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
