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
	char		already[MEM_SIZE];
	int			x;
	int			y;
	char		opcode;
	int			turfu;

	t_proc		emul;

	ft_bzero(already, sizeof(already));
	while (proc)
	{
		if (already[(proc->pc)])
		{
			proc = proc->n;
			continue ;
		}
		x = (proc->pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
		y = (proc->pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
		opcode = (proc->inst) ? proc->inst->id : ft_getchar(
		data()->vm.arene + (proc->pc * 2) % SIZE_CHAR_ARENE);
		if (DISPLAY_AURA)
		{
			if (opcode < 1 || opcode > 16)
				put_proc_bloc(img, &m->scene_img[2][27], x, y);
			else
				put_proc_bloc(img, &m->scene_img[2][28], x, y);
		}
		put_proc_bloc(bloc, &m->scene_img[2][-proc->player + 28], x, y);
		turfu = 0;
		if (opcode > 0 && opcode < 17)
		{
			emul.pc = proc->pc % MEM_SIZE;
			if (ft_get_instruction(data()->vm.instructions, &data()->vm, &emul)
			&& ft_check_value_args(emul.args, emul.inst, &data()->vm, &emul))
				turfu = ((emul.pc_turfu / 2) % MEM_SIZE) - proc->pc;
			while (--turfu > 0)
			{
				emul.pc = (emul.pc + 1) % MEM_SIZE;
				x = (emul.pc % VMPERLINE) * VMSPACEBLANK + VMSTARTX + PROCDECALLAGEX;
				y = (emul.pc / VMPERLINE) * VMSPACELINE + VMSTARTY + PROCDECALLAGEY;
				put_proc_bloc(bloc, &m->scene_img[2][-proc->player + 28], x, y);
				put_proc_bloc(img, &m->scene_img[2][33], x, y);
			}
		}
		already[(proc->pc)] = 1;
		proc = proc->n;
	}
}
