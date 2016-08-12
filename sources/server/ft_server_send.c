#include "server.h"
#include "libft.h"

/*
** Envoie un message a tous les clients
*/
int		ft_server_send_message(t_server *server, char *message)
{
	int		nbr;
	int		ret ;
	ssize_t size_message;

	nbr = 0;
	size_message = ft_strlen(message);
	while (nbr < server->nbr_clients)
	{
		if ((send(server->clients[nbr], message, size_message, 0)) != size_message)
			return (-1);
	//	ret = write(server->clients[nbr], message, size_message);
		//ft_putnbr(ret);
		++nbr;
	}
	return (1);
}
