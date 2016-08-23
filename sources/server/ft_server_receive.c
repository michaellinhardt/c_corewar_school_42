#include "libft.h"
#include "client.h"
#include <sys/socket.h>

/*
** Fonctionqui recois un message du client
** Param 1 : fd du Socket
** Param 2 : le buffer a remplir (size max 1023)
** Renvoie  1
*/

// faire des whiles
int		ft_server_receive_message_all(t_server *server, char *receive)
{
	int ret;
	int	nbr;

	nbr = 0;
	ret = -1;
	while (nbr < server->nbr_clients)
	{
		ret = recv(server->clients[nbr], (void *)&server->data_receive[nbr]
				, sizeof(&server->data_receive[nbr]), 0);
		/*
		if (ret > 0)
			receive[ret] = 0;
			*/
		++nbr;
	}
	return (1);
}

int		ft_server_receive_message(t_server *server, int fd_client)
{
	int ret;

	//ret = recv(fd_client, server->buf, BUFF_SIZE - 1, 0);
	ret = recv(fd_client, (void *)&server->data_receive[0],
			sizeof(&server->data_receive[0]), 0);
	if (ret > 0)
	{
		ft_putnbr(server->data_receive[0].nbr);
		ft_putendl(server->data_receive[0].name);
	}
	if (ret == -1)
		return (ret);
	/*
	if (ret > 0)
		server->buf[ret] = 0;
		*/
	return (ret);
}
