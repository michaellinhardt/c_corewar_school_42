#ifndef CLIENT_H
#define CLIENT_H

#include "server.h"
#include <sys/time.h>
#include "corewar_vm.h"

/*
** Strcuture Client
*/

typedef struct s_client
{
	int				fd_socket;
	struct timeval	timeout;
	char			buf[BUFF_SIZE];
	char			*champion;
	t_data			data_send;
	t_data			data_receive;
	// rajouter les infos du server
}				t_client;

/*
** Init
*/
void	ft_client_init(t_client *client, char *champion);
int		ft_client_socket(char bloquant, t_client *client);
int		ft_client_connexion(char *ip, char *port, t_client *client);
int		ft_client_send_message(t_client *client, char *message);
int		ft_client_receive_message(t_client *client);
int		ft_client_check_read_sockets(t_client *client);
#endif
