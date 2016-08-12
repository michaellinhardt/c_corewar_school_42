#include "libft.h"
#include <sys/socket.h>
/*
** Fonction qui envoi un message au server
** Param 1 : le fd du socket
** Param 2: le message a envoyer
** return -1 en cas d'erreur
*/

int		ft_client_send_message(int fd_socket, char *message)
{
	ssize_t size_message;

	size_message = ft_strlen(message);
	if ((send(fd_socket, message, size_message, 0)) != size_message)
		return (-1);
	return (1);
}
