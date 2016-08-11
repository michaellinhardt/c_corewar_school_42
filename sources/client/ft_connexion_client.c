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


/*
 * Rajouter gethostbyname ??? Pour se connecter au serveur, au lieu de marquer ip
 * */
int	ft_socket_client(char bloquant)
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
	return (fd_socket);
}

/*
** Fonction qui se connecte au serveur
** Param 1: L'ip du serveur
** Param 2: Le port du serveur
** Param 3: Le fd du socket
** Renvoie -1 en cas d'erreur
*/

int	ft_connexion_client(char *ip, char *port, int fd_socket)
{
	struct sockaddr_in address;

	ft_bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(ip);
	address.sin_port = htons(ft_atoi(port));
	if ((connect(fd_socket, (struct sockaddr *) &address, sizeof(address))) == -1)
		return (-1);
	//envoyer non champion
	ft_client_send_message(fd_socket, "Aodren");

	return (1);
}
