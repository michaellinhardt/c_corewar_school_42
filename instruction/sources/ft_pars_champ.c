#include <fcntl.h>
#include <unistd.h>
#include "instructions.h"
#include "libft.h"
/*
** fonction basique pour les tests pour recuperer le champions
** check juste magique number pas le reste
*/

static int 	ft_recup_champ(char *str, t_champion *champion)
{
	char line[100];
	int ret;
	int fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	read (fd, line, 4); // MAGIC NUMBER
	read (fd, champion->name, PROG_NAME_LENGTH);
	ft_print_memory(champion->name, PROG_NAME_LENGTH);
	read (fd, line, 6); //heu.....
	read (fd, champion->comment, COMMENT_LENGTH);
	ft_putchar('\n');
	ft_print_memory(champion->comment, COMMENT_LENGTH);
	read (fd, champion->prog_size, CHAMP_MAX_SIZE);
	close (fd);
	return (1);
}

int		ft_pars_champs(t_champion *champions, char **av, int ac)
{
	unsigned int champs;

	champs = 0;
	if (ac < 2)
		return 0;
	av++;
	while (ac > 1 && champions)
	{
		if (!(ft_recup_champ(*av, champions)))
			return 0;
		++champs;
		av++;
		champions++;
		ac--;
	}
	return (champs);
}
