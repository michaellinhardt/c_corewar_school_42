#include "server.h"

#include "libft.h"
void	ft_client_disconnect(t_server *server, int fd_client, int nbr_client)
{
	int nbr;
	// rcuperer le nom du server pour afficher qui est deconnecter
	ft_putendl("Client deconnecte");
	close(fd_client);
	// voir plus tard pour le name du client
	//recalculer le max
	ft_memmove(&server->clients[nbr_client], &server->clients[nbr_client + 1],
			sizeof(&server->clients[MAX_CONNECT]) -
			sizeof(&server->clients[nbr_client]));
	server->nbr_clients--;
	nbr = 0;
	while (nbr < server->nbr_clients)
	{
		server->max = server->clients[nbr] > server->max ?
			server->clients[nbr] : server->max;
		nbr++;
	}
}
