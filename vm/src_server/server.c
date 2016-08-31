/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 00:46:08 by pba               #+#    #+#             */
/*   Updated: 2016/08/28 18:00:32 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** 1- create a server socket.
** 2- make it wait for connection (request).
** 3- close the socket when all's finished.
*/

static void				usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int						main(int ac, char **av, char **env)
{
	int					sock;
	char				buf[PATH_MAX];
	t_env				*serv_env;

	if (ac != 2)
		usage(av[0]);
	if ((sock = create_server(av[1])) == -1)
		exit(-1);
	if ((serv_env = init_env(env)) == NULL)
	{
		ft_putstr_fd("error : attempt to connect the server failed.", 2);
		return (0);
	}
	ft_putstr_green_fd("Server connected\n", 2);
	request(serv_env, sock, buf);
	free(serv_env);
	close(sock);
	return (0);
}
