#include "server.h"
#include "libft.h"

/*
** Envoie un message a tous les clients
** Voir pour boucler sur send si on arrive pas a bien envoyer toutes les
** donness
** Renvoie -1 ne cas d'erreur
*/

int		ft_server_send_message_all(t_server *server, char *message)
{
	int		nbr;
	int		ret;
	ssize_t size_message;

	nbr = 0;
	//size_message = ft_strlen(message);
	size_message = sizeof(&server->data_send);
	while (nbr < server->nbr_clients)
	{
//		while ((ret = send(server->clients[nbr], message, size_message, 0))
//				!= size_message)
		while ((ret = send(server->clients[nbr],
						(const void *)&server->data_send, size_message, 0))
				!= size_message)
		{
			if (ret == -1)
			{
				ft_server_disconnect_client(server, server->clients[nbr],
						server->nbr_clients);
				return (0);
			}
			size_message -= ret;
		}
		++nbr;
	}
	return (1);
}

/*
** Envoi un message au client
** Renvoie -1 en cas d'erreur
*/

int		ft_server_send_message(int fd_client, char *message, t_server *server)
{
	ssize_t size_message;

	size_message = sizeof(&server->data_send);
	//size_message = ft_strlen(message);
	//if ((send(fd_client, message, size_message, 0)) != size_message)
	//	return (-1);

	// faire une while
	if ((send(fd_client, (const void *)&server->data_send, size_message, 0)) != size_message)
		return (-1);
	return (1);
}
