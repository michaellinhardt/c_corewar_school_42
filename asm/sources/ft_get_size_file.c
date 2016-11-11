/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:21 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:21 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_get_size_file(int fd)
{
	int size;

	size = lseek(fd, 0, SEEK_END);
	if (size == -1)
		return (-1);
	if (lseek(fd, 0, SEEK_SET) == -1)
		return (-1);
	return (size);
}
