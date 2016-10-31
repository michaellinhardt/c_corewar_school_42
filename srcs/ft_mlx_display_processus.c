#include "ft_corewar.h"

void	put_proc_bloc(t_img *img, t_img *bloc, int x, int y)
{
	int			*pbloc;
	int			*pimg;

	pbloc = (int *)bloc->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < BLOCY)
	{
		x = -1;
		while (++x < BLOCX)
		{
			// pimg[++(img->i)] = 0;
			pimg[++(img->i)] = pbloc[y * BLOCX + x];
		}
		img->i = img->i - x + WIN_X;
	}
}

void	display_bloc(t_dmlx *m, t_proc *proc, t_img *img, t_img *bloc)
{
	return ;
	ft_printf("proc_id %d ¶ wait: %d, turfu: %d\n", proc->id, proc->wait, proc->pc_turfu);
	if (proc->inst)
		ft_printf("%s\n", proc->inst->name);
	(void)m;
	(void)proc;
	(void)img;
	(void)bloc;
}

void	display_processus(t_dmlx *m, t_proc *proc, t_img *img, t_img *bloc)
{
	int			x;
	int			y;
	char		opcode;
	int			turfu;
	t_proc		emul;

	if (m->scene == END)
		return ;
	ft_bzero(m->already, sizeof(m->already));
	while (proc)
	{
		if (m->already[(proc->pc)])
		{
			proc = proc->n;
			continue ;
		}
		x = (proc->pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
		y = (proc->pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
		opcode = (proc->inst) ? proc->inst->id : ft_getchar(
		data()->vm.arene + (proc->pc * 2) % SIZE_CHAR_ARENE);
		put_proc_bloc(img, &m->scene_img[VM][-proc->player + 28], x, y);
		put_proc_bloc(bloc, &m->scene_img[VM][-proc->player + 28], x, y);
		turfu = 0;
		if (opcode > 0 && opcode < 17)
		{
			emul.pc = proc->pc % MEM_SIZE;
			if (ft_get_instruction(data()->vm.instructions, &data()->vm, &emul))
			{
				ft_get_oc_p(&data()->vm, &emul);
				turfu = ((emul.pc_turfu / 2) % MEM_SIZE) - proc->pc;
			}
			while (--turfu > 0)
			{
				emul.pc = (emul.pc + 1) % MEM_SIZE;
				x = (emul.pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
				y = (emul.pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
				put_proc_bloc(img, &m->scene_img[VM][33], x, y);
				put_proc_bloc(bloc, &m->scene_img[VM][33], x, y);
			}
		}
		m->already[(proc->pc)] = 1;
		proc = proc->n;
	}
}
