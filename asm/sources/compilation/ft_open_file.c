/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:31 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:31 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

char		*ft_create_name(char *name, int size)
{
	char	*name_cor;

	name_cor = (char *)ft_memalloc(sizeof(char) * (size + 5));
	ft_memcpy(name_cor, name, size);
	ft_memcpy(name_cor + size, ".cor", 4);
	return (name_cor);
}

static int	ft_get_size_extention(char *name)
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

int			ft_create_file(char *name)
{
	int		size;
	int		fd;
	char	*name_cor;

	size = ft_get_size_extention(name);
	name_cor = ft_create_name(name, size);
	if ((fd = open(name_cor, O_CREAT | O_WRONLY,
					S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)) == -1)
		fd = open(name_cor, O_WRONLY,
				S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if (name_cor)
		free(name_cor);
	return (fd);
}
