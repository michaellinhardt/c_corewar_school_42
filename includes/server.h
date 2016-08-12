#ifndef SERVER_H
#define SERVER_H

#define BUFF_SIZE 1024
#define MAX_CONNECT 3

#include <arpa/inet.h>
#include <sys/time.h>
/*
** address -> info du serveur/ clients
** clients -> listes des fd des clients
** fd_socket -> fd du socket
** name -> nom des clients;
*/

typedef struct	s_server
{
	char				name[MAX_CONNECT + 1][10];
	char				buf[BUFF_SIZE];
	int					clients[MAX_CONNECT];
	int					nbr_clients;
	int					fd_socket;
	int					max;// le fd max pour select + 1
	struct sockaddr_in	address;
	struct timeval		timeout;

}				t_server;

void	ft_init_server(t_server *server);
int		ft_socket_serveur(int bloquant, t_server *server);
int		ft_init_serveur(char *ip, char *port, t_server *server);
int		ft_accept_connection(t_server *server);
int		ft_server_send_message(t_server *server, char *message);
int		ft_server_receive_message(t_server *server,  int fd_client);
int		ft_server_receive_message_all(t_server *server, char *receive);
int		ft_server_check_read_sockets(t_server *server);
void	ft_client_disconnect(t_server *server, int fd_client, int nbr_client);

#endif
