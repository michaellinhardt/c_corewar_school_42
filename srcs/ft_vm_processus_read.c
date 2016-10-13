/*
** LECTURES DES PROCESSUS
*/
#include "ft_corewar.h"

void	processus_read(t_dvm *v, t_proc *begin)
{
	int pc;
	int opcode;
	t_proc *proc = begin;
	v->graphic += 0;
	opcode = 0;

	if (v->options.cycles)
		ft_printf("It is now cycle %d\n", v->cycle);
	while ( proc )
	{
		if (!proc->wait)
		{
				proc->pc_turfu = proc->pc * 2;
				if (!(ft_get_instruction(v->instructions, v, proc)))
				{
					proc->pc = (proc->pc + 1) % 4096 ;
					proc = proc->n;
					continue ;
				}
		}
		else if (proc->wait == 1)
		{
			/*
			opcode = ft_getchar(v->arene + proc->pc * 2);
			if (proc->inst->id != 1 &&  opcode != proc->inst->id)
			{
				ft_putendl("ok");
			//	proc->wait = 0;
//]				proc->pc = proc->pc_turfu / 2;
			//	proc = proc->n;
				//continue;
			}
			*/
			pc = proc->pc;
			proc->inst->f_instructions(v, *proc->inst, proc);
			if (proc->pc >= MEM_SIZE || proc->pc < 0)
			{
				ft_printf("ici: %d\n", proc->inst->id);
				exit(0);
			}
			/*
			if (v->options.movements)
			{
				ft_printf("ADV %d (%#06x -> %#06x) ", proc->pc - pc, pc, proc->pc);
				pc *= 2;
				while (pc  < proc->pc * 2)
				{
					if (*(v->arene + pc) >= 65)
						ft_putchar(*(v->arene + pc++) + 32);
					else
						ft_putchar(*(v->arene + pc++));
					if (*(v->arene + pc) >= 65)
						ft_putchar(*(v->arene + pc++) + 32);
					else
						ft_putchar(*(v->arene + pc++));
					ft_putchar(' ');
				}
				ft_putchar('\n');
			}
			*/
		}
		else
		{
			/*
			opcode = ft_getchar(v->arene + proc->pc * 2);
			if (proc->inst->id != 1 &&  opcode != proc->inst->id)
			{
				ft_putendl("ok");
		//		proc->wait = 0;
		//		proc->pc = proc->pc_turfu / 2;
			//	proc = proc->n;
			//	continue;
			}
			*/
		}
		proc->wait--;
		proc = proc->n;
	}
}
/*
void	processus_read(t_dvm *v, t_proc *begin)
{
	int pc;
	int opcode;
	t_proc *proc = begin;
	v->graphic += 0;


	pc = 0;
	opcode = 0;
	if (v->options.cycles)
		ft_printf("It is now cycle %d\n", v->cycle);
	while (proc)
	{

		if (!proc->wait)
		{
			if (proc->inst)
			{
				opcode = ft_getchar(v->arene + proc->pc * 2);
				if (proc->inst->id != 1 &&  opcode != proc->inst->id)
				{
					proc->wait = 0;
					//proc->pc = proc->pc_turfu / 2;
					proc = proc->n;
					proc->inst = 0;
					continue;
				}
				proc->inst->f_instructions(v, *proc->inst, proc);
				proc->pc_turfu = proc->pc * 2;
				if (!(ft_get_instruction(v->instructions, v, proc)))
				{
					proc->pc = (proc->pc + 1) % 4096 ;
					proc = proc->n;
					continue ;
				}
			}
			else
			{
				proc->pc_turfu = proc->pc * 2;
				if (!(ft_get_instruction(v->instructions, v, proc)))
				{
					proc->pc = (proc->pc + 1) % 4096 ;
					proc = proc->n;
					continue ;
				}
				proc->wait--;
			}
		}
		proc->wait--;
		proc = proc->n;
	}
}
*/
