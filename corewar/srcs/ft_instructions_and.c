/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_and.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:45 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:45 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	ft_log_and(t_dvm *vm, t_proc *proc, int registre)
{
	log_inst(proc->player, proc->id, "AND");
	if (vm->options.operations)
	{
		if (proc->id < 10000)
			ft_printf("P%5d | and %d %d r%d\n", proc->id,
					proc->args[0].value, proc->args[1].value, registre);
		else if (proc->id < 100000)
			ft_printf("P%6d | and %d %d r%d\n", proc->id,
					proc->args[0].value, proc->args[1].value, registre);
		else
			ft_printf("P%7d | and %d %d r%d\n", proc->id,
					proc->args[0].value, proc->args[1].value, registre);
	}
}

void		ft_instructions_and(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{
			ft_log_and(vm, proc, registre);
			if ((*(proc->ireg + registre - 1) =
						proc->args[0].value & proc->args[1].value))
				proc->carry = 0;
			else
				proc->carry = 1;
		}
	}
	if ((proc->pc = (proc->pc_turfu / 2)) >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
}
