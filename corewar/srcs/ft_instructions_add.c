/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:44 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:44 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	ft_log_add(t_dvm *vm, t_proc *proc, int *registre)
{
	log_inst(proc->player, proc->id, "ADD");
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | add r%d r%d r%d\n", proc->id, registre[1],
					registre[2], registre[0]);
		else if (proc->id < 100000)
			ft_printf("P%6d | add r%d r%d r%d\n", proc->id, registre[1],
					registre[2], registre[0]);
		else
			ft_printf("P%7d | add r%d r%d r%d\n", proc->id, registre[1],
					registre[2], registre[0]);
	}
}

void		ft_instructions_add(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre[3];

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre[0] = proc->args[2].value;
		registre[1] = proc->args[0].value;
		registre[2] = proc->args[1].value;
		if (ft_get_args(proc))
		{
			ft_log_add(vm, proc, registre);
			proc->args[2].value = registre[0];
			if ((*(proc->ireg + registre[0] - 1) = proc->args[0].value
						+ proc->args[1].value))
				proc->carry = 0;
			else
				proc->carry = 1;
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
