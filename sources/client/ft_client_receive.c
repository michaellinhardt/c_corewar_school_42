#include "libft.h"
#include "client.h"
#include <sys/socket.h>

/*
** Fonctionqui recois un message du serveur
** Param 1 : fd du Socket
** Param 2 : le buffer a remplir (size max 1023)
** Renvoie le nombre d'octet lus
*/

int		ft_client_receive_message(t_client *client)
{
	int ret;

	ret = recv(client->fd_socket, client->buf, BUFF_SIZE - 1, 0);
	if (ret)
	{
		client->buf[ret] = 0;
		ft_putendl(client->buf);
	}
	return (ret);
}
