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
	char				name[MAX_CONNECT + 1][10];

}				t_server;

void	ft_init_server(t_server *server);
int		ft_socket_serveur(int bloquant, t_server *server);
int		ft_init_serveur(char *ip, char *port, t_server *server);
int		ft_accept_connection(t_server *server);
int		ft_server_send_message(t_server *server, char *message);

#endif
