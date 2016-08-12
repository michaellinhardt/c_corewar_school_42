#include "server.h"
#include <sys/select.h>

#include <sys/types.h>
#include <unistd.h>


/*
 ** Fonction qui check l'etat des sockets
 */
#include "libft.h"
int		ft_server_check_read_sockets(t_server *server)
{
	int				ret;
	int				clients;
	fd_set			fdset;

	clients = 0;
	FD_ZERO(&fdset);

	FD_SET(0, &fdset); // pour faire un exit
	FD_SET(server->fd_socket, &fdset); //socket du server

	/*
	 ** Clients sockets
	 */
	while (clients < server->nbr_clients)
		FD_SET(server->clients[clients++], &fdset);
	if ((ret = select(server->max + 1, &fdset, 0, 0, &server->timeout)) == -1)
	{
		ft_putendl("erreur");
		return (ret);
	}
	if (FD_ISSET(0, &fdset))
	{
		char buf[1024];
		int		fin;
		fin = read(0, buf, 1023);
		buf[fin] = 0;
		if (*buf == 'q')
			return (2);

	}
	/*
	 ** Connexion d'un client
	 */
	if (FD_ISSET(server->fd_socket, &fdset))
	{
		if ((ret = ft_accept_connection(server)) != -1)
			FD_SET(ret, &fdset);
	}
	clients = 0;
	/*
	 ** Un message d'un client
	 */
	while (clients < server->nbr_clients)
	{
		if (FD_ISSET(server->clients[clients], &fdset))
		{
			if ((ft_server_receive_message(server, server->clients[clients])) == -1)
			{
				ft_server_disconnect_client(server, server->clients[clients], clients);
			}
		}
		++clients;
	}
	return (1);
}
