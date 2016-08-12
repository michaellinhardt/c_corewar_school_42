#include "libft.h"
#include "client.h"
#include <sys/socket.h>

/*
** Fonction qui envoi un message au server
** Param 1 : le fd du socket
** Param 2: le message a envoyer
** return -1 en cas d'erreur
*/

int		ft_client_send_message(t_client *client, char *message)
{
	ssize_t size_message;

	size_message = ft_strlen(message);
	if ((send(client->fd_socket, message, size_message, 0)) != size_message)
		return (-1);
	return (1);
}
