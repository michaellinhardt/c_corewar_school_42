#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "op.h"
#define CHAMPION_SIZE PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE
typedef struct	s_champion
{
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	char		prog_size[CHAMP_MAX_SIZE];

}				t_champion;

char	*ft_create_vm(void);
void	ft_display_vm(char *vm);
int		ft_pars_champs(t_champion *champion, char **av, int ac);
void	ft_place_champions(char *vm, t_champion *champions, int champs);
#endif
