#include "ft_corewar.h"
/*
 * Ce fichier charge les img lié à la scene actuel
 */

void		scene_img_file_load(t_dmlx *m, t_scene_img *s
									, char *file, int img_id)
{
	t_img	*new;
	// place dans -> data->mlx->scene_img[m->scene].l[ft_atoi(f->d_name)]
	// l'image chargé depuis le chemin "file" et le str de l'image sera donc:
	// data->mlx->scene_img[m->scene].l[ft_atoi(f->d_name)]->str
	// s correspond à un raccourci pour data->mlx->scene_img[20]
	if (!(new = (t_img *)ft_memalloc(sizeof(t_img) * 1)))
		exit1(1, data(), "Cant malloc the t_img struct.");
	new->img = mlx_xpmtostruct(m, new, file);
	s[m->scene].l[img_id] = new;
}

int			scene_img_file(t_dmlx *m, DIR *dir, struct dirent *f, char *path)
{
	char	*folder;
	char	*file;

	// lit le dossier d'image de cette adresse: ./xpm/scene_<name>.xpm
	// <name> est arbitraire, c'est le numéro précédant le _ et le .xpm
	// qui importe pour la détection du dossier
	ft_printf("%!./xpm/%s", &folder, path);
	if (!(dir = opendir(folder)))
		exit1(1, data(), "Cant open xpm sub dir.");
	while ((f = readdir(dir)))
	{
		if (!ft_strstr(f->d_name, ".xpm"))
			continue ;
		ft_printf("%!%s/%s", &file, folder, f->d_name);
		l(1, f->d_name, "   loading xpm file");
		scene_img_file_load(m, m->scene_img
			, file, ft_atoi(f->d_name));
	}
	closedir(dir);
	ft_strdel(&folder);
	ft_strdel(&file);
	return (1);
}

void		scene_img_folder(t_dmlx *m, DIR *dir, struct dirent *f)
{
	// parcour le dossier ./xpm
	// celui ci contiens les dossier de chaque scene, eux même contenant
	// les .xpm de chaque scene
	if (!(dir = opendir("./xpm")))
		exit1(1, data(), "Cant open xpm dir.");
	while ((f = readdir(dir)))
	{
		if (!ft_strstr(f->d_name, ".xpm"))
			continue ;
		else if (ft_atoi(f->d_name) == m->scene && l(1, f->d_name
			, "loading xpm from scene folder") && scene_img_file(m
			, (DIR *)NULL, (struct dirent *)NULL, f->d_name))
			break ;
	}
	closedir(dir);
}

/*
 * Cette fonction pilote le chargement des image lié à la scene en cours
 */
void		scene_img(t_data *d, t_dmlx *m)
{
	d->mlx.loop += 0;
	if (m->img_isload[m->scene] == 1)
		return ;
	scene_img_folder(m, (DIR *)NULL, (struct dirent *)NULL);
	m->img_isload[m->scene] = 1;
}
