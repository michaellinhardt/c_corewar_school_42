/*
** GERE LES INSTRUCTIONS
*/
#include "ft_corewar.h"

/*
** EXEMPLE
unsigned char	convert( int start, int end )
{
	return -> convert "ff" -> 255;
}
void	live( int pos )
{
	int param = convert( pos + 1, pos + 4 );
}
*/

void	op_live(t_dvm *v, t_proc *proc)
{
	v->graphic += 0;
	proc->wait++;
	// si le wait correspond au temps d'attente, on execute
	if (proc->wait == 10)
	{
		proc->live++;
		proc->i += 4;
		if (proc->i > 4095)
			proc->i -= 4095;
		proc->wait = 0;
		l2(-2, "op_live()", "live proc", proc->id);
	}
}

void	op_fork(t_dvm *v, t_proc *proc)
{
	int		i;

	v->graphic += 0;
	proc->wait++;
	// si le wait correspond au temps d'attente, on execute
	if (proc->wait == 800)
	{
		i = proc->i + 64;
		if (i > 4095)
			i -= 4095;
		proc_new(data(), (t_proc *)NULL, proc->player, i);
		proc->i += 4;
		if (proc->i > 4095)
			proc->i -= 4095;
		proc->wait = 0;
	}
}

void	instructions(t_dvm *v, t_proc *proc)
{
	v->graphic += 0;
	if (v->arene[proc->i * 2] == '0' && v->arene[proc->i * 2 + 1] == '1'
	&& v->arene[proc->i * 2 + 2] && v->arene[proc->i * 2 + 2] == 'F'
	&& v->arene[proc->i * 2 + 3] && v->arene[proc->i * 2 + 3] == 'F')
		op_live(v, proc);
	else if (v->arene[proc->i * 2] == '0' && v->arene[proc->i * 2 + 1] == 'C'
	&& v->arene[proc->i * 2 + 2] && v->arene[proc->i * 2 + 2] == '0'
	&& v->arene[proc->i * 2 + 3] && v->arene[proc->i * 2 + 3] == '0')
		op_fork(v, proc);
	else
	{
		proc->i++;
		if (proc->i > 4095)
			proc->i -= 4095;
	}
}
