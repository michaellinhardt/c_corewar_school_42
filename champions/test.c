/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 22:00:43 by pba               #+#    #+#             */
/*   Updated: 2016/10/11 00:48:02 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_header
{
	unsigned int	magic;
	char 			prog_name[129];
	unsigned int	prog_size;
	char			comment[2049];
}					t_header;

int 				main(void)
{
	int				fd;
	
	t_header		header;
	bzero(&header, sizeof(t_header));
	header.magic = 0xea83f3;
	strcpy(header.prog_name, "test");
	header.prog_size = 128;
	strcpy(header.comment, "This is a comment");
	fd = open("test_binary", O_CREAT | O_RDWR);
	write(fd, &header, sizeof(t_header));
	return (0);
}

