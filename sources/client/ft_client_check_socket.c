#include "client.h"
#include "libft.h"
#include <sys/select.h>
#include <unistd.h>

int		ft_client_check_read_sockets(t_client *client)
{
	int			ret;
	fd_set		fdset;

	FD_ZERO(&fdset);
	FD_SET(client->fd_socket, &fdset);
	if ((ret = select(client->fd_socket + 1, &fdset, 0, 0,
					&client->timeout)) == -1)
		return (ret);
	else if (FD_ISSET(client->fd_socket, &fdset))
	{
		if ((ft_client_receive_message(client)) == -1)
		{
			ft_putendl("server deconnecter");
			return (-1);
		}
	}
	return (1);
}
