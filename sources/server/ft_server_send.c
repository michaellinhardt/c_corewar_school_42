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
	size_message = ft_strlen(message);
	while (nbr < server->nbr_clients)
	{
		if ((send(server->clients[nbr], message, size_message, 0))
				!= size_message)
			return (-1);
		++nbr;
	}
	return (1);
}

/*
** Envoi un message au client
** Renvoie -1 en cas d'erreur
*/

int		ft_server_send_message(int fd_client, char *message)
{
	ssize_t size_message;

	size_message = ft_strlen(message);
	if ((send(fd_client, message, size_message, 0)) != size_message)
		return (-1);
	return (1);
}
