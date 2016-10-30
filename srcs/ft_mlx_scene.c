#include "ft_corewar.h"

void		scene(t_data *d, t_dmlx *m)
{
	if (m->scene == VM)
		vm(&d->vm, d->vm.cperloop);
	else if (m->scene == VM_INIT)
		vm_init(d, &d->vm);
	else if (m->scene == INTRO_LOAD)
		intro_load(m, &m->scene_img[0][0], &m->scene_img[0][1]);
	// else if (d->scene == INTRO_MENU)
	// 	intro_menu(&d->pressany, &d->intro);
	// else if (d->scene == INTRO_OUT)
	// 	intro_out(d, &d->img, &d->intro, &d->pressany);
}
