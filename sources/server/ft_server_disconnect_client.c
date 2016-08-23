#include "server.h"
#include "libft.h"

/*
** Deconnecte le client indiquer par le fd_client
** Param 1 struct server
** Param 2 socket lie au client
** Param 3 numero du client
** Voir pour retourner le nom du client deconneter
*/

void	ft_server_disconnect_client(t_server *server,
		int fd_client, int nbr_client)
{
	int nbr;

	//ft_putstr(server->name[nbr_client]);
	ft_putendl(" deconnecte");
	close(fd_client);
	ft_memmove(&server->clients[nbr_client], &server->clients[nbr_client + 1],
			&(server->clients[MAX_CONNECT]) -
			&(server->clients[nbr_client]));
	/*
	ft_memmove(&server->name[nbr_client], &server->name[nbr_client + 1],
		(server->name[MAX_CONNECT] -
			server->name[nbr_client]));
			*/
	(server->nbr_clients)--;
	nbr = 0;
	while (nbr < server->nbr_clients)
	{
		server->max = server->clients[nbr] > server->max ?
			server->clients[nbr] : server->max;
		nbr++;
	}
}

void	ft_server_disconnect_client_all(t_server *server)
{
	int clients;
	int	i;

	clients = 0;
	ft_putendl("deconnection de tous les clients");
	while (clients < server->nbr_clients)
		close(server->clients[clients++]);
	ft_bzero(&server->clients, sizeof(&server->clients));
	i = 0;
	/*
	while (i < server->nbr_clients)
	{
		ft_bzero(server->name[i], sizeof(server->name[i]));
		++i;
	}
	*/
	server->nbr_clients = 0;
	server->max = 0;
}
