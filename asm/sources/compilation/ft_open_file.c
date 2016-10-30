#include "ft_asm.h"
#include "libft.h"

char	*ft_create_name(char *name, int size)
{
	char	*name_cor;

	name_cor = (char *)ft_memalloc(sizeof(char) * (size + 5));
	ft_memcpy(name_cor, name, size); 
	ft_memcpy(name_cor + size, ".cor", 4);
	ft_print_memory(name_cor, size + 4);
	return (name_cor);
}

static	int		ft_get_size_extention(char *name)
{
	int		size;

	size = ft_strlen(name);
	while (size && *(name + size) != '.')
		--size;
	if (!size)
		return (ft_strlen(name));
	else
		return (size);
}

#include <fcntl.h>
int		ft_create_file(char *name)
{
	int 	size;
	int		fd;
	char	*name_cor;

	size = ft_get_size_extention(name);
	name_cor = ft_create_name(name, size);
	if ((fd = open(name_cor, O_CREAT | O_WRONLY)) == -1)
	{
		ft_putendl("fichier deja exisant");
		fd = open(name_cor, O_APPEND, O_WRONLY);
	}
	return (fd);
}
