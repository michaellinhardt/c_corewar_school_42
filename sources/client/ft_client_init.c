#include "client.h"
#include "libft.h"

/*
** Init de la struct client
*/

void	ft_client_init(t_client *client, char *champion)
{
	client->fd_socket = -1;
	client->timeout.tv_sec = 0;
	client->timeout.tv_usec = 200000;
	client->champion = champion;
	ft_bzero(client->buf, BUFF_SIZE);
}
