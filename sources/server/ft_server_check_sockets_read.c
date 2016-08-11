#include "server.h"
#include <sys/select.h>

#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>


/*
 ** Fonction qui check l'etat des sockets
 */
#include "libft.h"
int		ft_check_sockets(t_server *server)
{
	int				ret;
	int				clients;
	fd_set			fdset;
	struct timeval	timeout; // a opti;

	clients = 0;
	FD_ZERO(&fdset);

	FD_SET(server->fd_socket, &fdset); //socket du server

	timeout.tv_sec = 0;
	timeout.tv_usec = 200000;
	/*
	 ** Clients sockets
	 */
	while (clients < server->nbr_clients)
		FD_SET(server->clients[clients++], &fdset);
	if ((ret = select(server->max + 1, &fdset, 0, 0, &timeout)) == -1)
	{
		ft_putendl("erreur");
		return (ret);
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
				ft_client_disconnect(server, server->clients[clients], clients);
			}
		}
		++clients;
	}
	return (1);
}
