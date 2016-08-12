#include "libft.h"
#include "client.h"
#include <sys/socket.h>

/*
** Fonctionqui recois un message du client
** Param 1 : fd du Socket
** Param 2 : le buffer a remplir (size max 1023)
** Renvoie  1
*/

int		ft_server_receive_message_all(t_server *server, char *receive)
{
	int ret;
	int	nbr;

	nbr = 0;
	ret = -1;
	while (nbr < server->nbr_clients)
	{
		ret = recv(server->clients[nbr], receive, BUFF_SIZE - 1, 0);
		if (ret > 0)
		{
			receive[ret] = 0;
//			ft_putendl(receive);
		}
		++nbr;
	}
	return (1);
}

int		ft_server_receive_message(t_server *server,  int fd_client)
{
	int ret;

	ret = recv(fd_client, server->buf, BUFF_SIZE -1, 0);
	if (ret == -1)
	{
		return (ret);
	}

	if (ret > 0)
	{
		server->buf[ret] = 0;
	//	ft_putendl(server->buf);
	}
	return (ret);
}
