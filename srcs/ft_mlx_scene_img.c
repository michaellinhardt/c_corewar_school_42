#include "ft_corewar.h"

int			scene_img_file(t_dmlx *m, DIR *dir, struct dirent *f, char *path)
{
	char	*folder;
	char	*file;

	ft_printf("%!./xpm/%s", &folder, path);
	if (!(dir = opendir(folder)))
		exit1(1, data(), "Cant open xpm sub dir.");
	while ((f = readdir(dir)))
	{
		if (!ft_isdigit(f->d_name[0]) || !ft_strstr(f->d_name, ".xpm"))
			continue ;
		ft_printf("%!%s/%s", &file, folder, f->d_name);
		l1(1, f->d_name, "   loading xpm file");
		m->scene_img[m->scene][ft_atoi(f->d_name)].img = mlx_xpmtostruct(m
			, &m->scene_img[m->scene][ft_atoi(f->d_name)], file);
		ft_strdel(&file);
	}
	closedir(dir);
	ft_strdel(&folder);
	return (1);
}

void		scene_img_folder(t_dmlx *m, DIR *dir, struct dirent *f)
{
	if (!(dir = opendir("./xpm")))
		exit1(1, data(), "Cant open xpm dir.");
	while ((f = readdir(dir)))
	{
		if (!ft_strstr(f->d_name, ".xpm"))
			continue ;
		else if (ft_atoi(f->d_name) == m->scene && l1(1, f->d_name
			, "loading xpm from scene folder") && scene_img_file(m
			, (DIR *)NULL, (struct dirent *)NULL, f->d_name))
			break ;
	}
	closedir(dir);
}

void		scene_layout_init(t_img *i)
{
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 255;
		i->str[i->i + 1] = 255;
		i->str[i->i + 2] = 255;
		i->str[i->i + 3] = 255;
	}
}

void		scene_img(t_data *d, t_dmlx *m)
{
	d->mlx.loop += 0;
	if (m->img_isload[m->scene] == 1)
		return ;
	scene_img_folder(m, (DIR *)NULL, (struct dirent *)NULL);
	if (m->scene == 2)
		scene_layout_init(&m->scene_img[2][26]);
	m->img_isload[m->scene] = 1;
}
