#include "libft.h"
#include "client.h"
#include <sys/socket.h>

/*
** Fonctionqui recois un message du serveur
** Param 1 : fd du Socket
** Param 2 : le buffer a remplir (size max 1023)
** Renvoie le nombre d'octet lus
*/

int		ft_client_receive_message(int fd_socket, char *receive)
{
	int ret;

	ret = recv(fd_socket, receive, BUFF_SIZE - 1, 0);

	if (ret)
	{
		receive[ret] = 0;
		ft_putendl(receive);
	}
	return (ret);
}
