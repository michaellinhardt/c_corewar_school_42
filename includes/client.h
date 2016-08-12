#ifndef CLIENT_H
#define CLIENT_H

#include "server.h"
#include <sys/time.h>
/*
** Strcuture Client
*/

typedef struct s_client
{
	int				fd_socket;
	struct timeval	timeout;
	char			buf[BUFF_SIZE];
	// rajouter les infos du server
}				t_client;

/*
** Init
*/
//void	ft_init_client(t_client *client);
int		ft_client_socket(char bloquant, t_client *client);
int		ft_client_connexion(char *ip, char *port, t_client *client);
int		ft_client_send_message(int fd_socket, char *message);
int		ft_client_receive_message(t_client *client);
int		ft_client_check_read_sockets(t_client *client);
#endif
