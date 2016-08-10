#ifndef CLIENT_H
#define CLIENT_H

#include "serveur.h"
/*
** Strcuture Client
*/

/*
typedef struct s_client
{
	int			fd_socket;

}				t_client;
*/

/*
** Init
*/
//void	ft_init_client(t_client *client);
int		ft_socket_client(char bloquant);
int		ft_connexion_client(char *ip, char *port, int fd_socket);
int		ft_client_send_message(int fd_socket, char *message);
int		ft_client_receive_message(int fd_socket, char *receive);
#endif
