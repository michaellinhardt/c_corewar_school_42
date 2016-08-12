#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libft.h"
#include "server.h"


void	ft_init_struct_server(t_server *server, char *champion)
{
//	ft_bzero(&server, sizeof(server));
	server->nbr_clients = 0;
	server->fd_socket = -1;
	server->max = 0;
	server->timeout.tv_sec = 0;
	server->timeout.tv_usec = 200000;
	ft_bzero(server->buf, BUFF_SIZE);
	server->champion = champion;
}

/*
** A voir si ne pas utiliser la meme fonction que client.....
*/

int		ft_socket_serveur(int bloquant, t_server *server)
{
	int opt;

	opt = 1;

	if ((server->fd_socket = socket(PF_INET, SOCK_STREAM, 6)) == -1)
		return (-1);
	if (bloquant == 1)
	{
		if ((ioctl(server->fd_socket, FIONBIO, &opt)) == -1)
			return (-1);
	}
	return (server->fd_socket);
}

/*
 * faire apparaitrre le nom ud serveur
 */
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>

int		ft_init_server(char *ip, char *port, t_server *server, char *champion)
{
	struct in_addr ad;
	struct hostent host;
	char name[255] = {0};

	ft_putnbr(gethostname(name, sizeof(name)));
	ft_print_memory(name, sizeof(name));
	ft_putendl(name);


	host = *gethostbyname(name);

//	ft_putnbr(
//	server->address.sin_family = AF_INET;
	server->address.sin_family = host.h_addrtype;
	//server->address.sin_addr.s_addr = inet_addr(ip);
	struct in_addr in;

	ft_bzero(&in, sizeof(in));
	ft_memmove(&in, host.h_addr_list[0], sizeof(in));
	ft_putendl(inet_ntoa(in));
	server->address.sin_addr.s_addr = inet_addr(inet_ntoa(in));
	//
	//obliger d'etre renseigner pas l'user
	//ou alors on se fout sur le prt 4242 et si pas dispo
	//on engeule l'user
	//
	server->address.sin_port = htons(ft_atoi(port));



	if ((bind(server->fd_socket, (struct sockaddr *) &server->address,
					sizeof(server->address))) == -1)
	{
		perror("bin () :");
		ft_putendl("c'est bind qui merde");
			return (-1);
	}
	if ((listen(server->fd_socket, MAX_CONNECT)) == -1)
		return (-1);
	server->max = server->fd_socket;
	return (1);
}

int		ft_accept_connection(t_server *server)
{
	unsigned int len;
	int			socket;

	len = sizeof(server->address);
	if ((socket = accept(server->fd_socket, (struct sockaddr *) &server->address,
				&len))  == -1)
		return (-1);
	server->clients[server->nbr_clients] = socket;
	server->nbr_clients++;
	server->max = socket > server->max ? socket : server->max;
	ft_putendl("accepter");
	return (socket);
}
