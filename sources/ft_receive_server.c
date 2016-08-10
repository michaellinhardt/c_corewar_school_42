#include "libft.h"
#include "client.h"
#include <sys/socket.h>

/*
** Fonctionqui recois un message du serveur
** Param 1 : fd du Socket
** Param 2 : le buffer a remplir (size max 1023)
** Renvoie le nombre d'octet lus
*/

int		ft_server_receive_message(t_server *server, char *receive)
{
	int ret;
	int	nbr;

	nbr = 0;
	while (nbr < server->nbr_clients)
	{
		ret = recv(server->clients[nbr], receive, BUFF_SIZE - 1, 0);
		if (ret)
		{
			receive[ret] = 0;
			ft_putendl(receive);
		}
		++nbr;
	}
	return (ret);
}
