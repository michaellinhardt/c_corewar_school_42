#include "client.h"
#include "libft.h"
/*
** Init de la struct client
*/

void	ft_init_cient(t_client *client)
{
	client->fd_socket = -1;
	client->timeout.tv_sec = 0;
	client->timeout.tv_usec = 200000;
	ft_bzero(client->buf, BUFF_SIZE);
}
