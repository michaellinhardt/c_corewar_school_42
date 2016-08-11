#ifndef SERVEUR_H
#define SERVEUR_H

#define BUFF_SIZE 1024
#define MAX_CONNECT 3

#include <arpa/inet.h>
/*
** address -> info du serveur/ clients
** clients -> listes des fd des clients
** fd_socket -> fd du socket
** name -> nom des clients;
*/

typedef struct	s_server
{
	struct sockaddr_in	address;
	int					clients[MAX_CONNECT];
	int					nbr_clients;
	int					fd_socket;
	int					max;// le fd max pour select + 1
	char				name[MAX_CONNECT + 1][10];
	char				buf[BUFF_SIZE];

}				t_server;

void	ft_init_server(t_server *server);
int		ft_socket_serveur(int bloquant, t_server *server);
int		ft_init_serveur(char *ip, char *port, t_server *server);
int		ft_accept_connection(t_server *server);
int		ft_server_send_message(t_server *server, char *message);
int		ft_server_receive_message(t_server *server,  int fd_client);
int		ft_server_receive_message_all(t_server *server, char *receive);
int		ft_check_sockets(t_server *server);
void	ft_client_disconnect(t_server *server, int fd_client, int nbr_client);

#endif
