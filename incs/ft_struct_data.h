#ifndef FT_STRUCT_DATA_H
# define FT_STRUCT_DATA_H
/*
 *	Header lié à la structure data
 */

/* DATA_REZ
 * Lien vers les structure du header ft_struct_rez.h
 * contient également des donné statique ou int
 */
typedef struct			s_drez
{
	// mode 0 pour solo, 1 pour serveur, 2 pour client
	char				mode;
}						t_drez;

/* DATA
 * La structure data pointe vers touts les donné et structure du prog'
 * Dans ce header son contenue les liens vers les différente structure,
 * elles même définis dans d'autres header
 */
typedef struct			s_data
{
	struct s_dmlx		mlx;
	struct s_drez		rez;
	struct s_dvm		vm;
	struct s_dargs		args;
	t_proc				*proc;
	t_proc				*procdie;
}						t_data;

#endif
