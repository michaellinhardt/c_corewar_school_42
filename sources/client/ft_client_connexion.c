#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libft.h"
#include "client.h"

/*
** Fonction qui creer un socket
** Rempli la struct client avec le fd ouver par le socket
** Param 1 : struct t_client
** Param 2 : booleean 1 : Pour activer le mode non bloquqnt sur le fd
** Renvoie le fd ouver par Socket
*/

int	ft_client_socket(char bloquant, t_client *client)
{
	int opt;
	int	fd_socket;

	opt = 1;
	if ((fd_socket = socket(PF_INET, SOCK_STREAM, 6)) == -1)
		return (-1);
	if (bloquant == 1)
	{
		if ((ioctl(fd_socket, FIONBIO, &opt)) == -1)
			return (-1);
	}
	client->fd_socket = fd_socket;
	return (fd_socket);
}

/*
** Fonction qui se connecte au serveur
** Param 1: L'ip du serveur
** Param 2: Le port du serveur
** Param 3: Le fd du socket
** Renvoie -1 en cas d'erreur
*/

int	ft_client_connexion(char *ip, char *port, t_client *client)
{
	struct sockaddr_in address;

	ft_bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(ip);
	address.sin_port = htons(ft_atoi(port));
	if ((connect(client->fd_socket, (struct sockaddr *)&address,
					sizeof(address))) == -1)
		return (-1);
	ft_client_send_message(client, client->champion);
	return (1);
}
