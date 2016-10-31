#include "ft_corewar.h"

void		scene(t_data *d, t_dmlx *m)
{
	if (m->scene == VM)
		vm(&d->vm, d->vm.cperloop);
	else if (m->scene == VM_INIT)
		vm_init(d, &d->vm);
	else if (m->scene == INTRO_LOAD)
		intro_load(m, &m->scene_img[0][0], &m->scene_img[0][1]);
	else if (m->scene == INTRO_MENU)
		intro_menu(&m->scene_img[0][2], &m->scene_img[0][1]);
	else if (m->scene == INTRO_OUT)
		intro_out(d, &m->scene_img[0][0], &m->scene_img[0][1]
			, &m->scene_img[0][3]);
	else if (m->scene == END)
		vm_end(d, &m->scene_img[0][0]);
}
