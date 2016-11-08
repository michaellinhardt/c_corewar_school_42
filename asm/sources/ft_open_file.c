#include <fcntl.h>

int		ft_open_file(char **argv)
{
	int fd;

	fd = open(*argv, O_RDONLY);
	return (fd);
}
