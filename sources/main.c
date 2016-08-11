#include "libft.h"
#include "client.h"


#include <netdb.h> //gethostbyname
#include <stdio.h> //printf
#include <arpa/inet.h> // inet_ntoa
#include <sys/socket.h> // socke
#include <sys/ioctl.h> // ioctl

#include <stdio.h>
#include <signal.h>
#include <sys/ioctl.h>
void		ft_sigint(int sig)
{
	char interrupt;

	interrupt = 3;
	ft_putendl("interrupr programme");
	close(sig);
	ioctl(0, TIOCSTI, &interrupt);
	signal(SIGINT, SIG_DFL);
}
int		main(int argc, char **argv)
{
	signal(SIGINT, ft_sigint);

	(void)argv;
	int fd;

	char buf[BUFF_SIZE];
	fd = -1;
	t_server server;

	//gerer les signaux pour close le fd lors d'un ctl c kill ctrl d
	//voir pur utiliser un keep-alive pour les clients
	if (argc > 1)
	{
		// on seras client -> pour les tests
		ft_putendl("Client");
		fd = ft_socket_client(1);
		if (fd == -1)
			ft_putendl("error fd");
		if ((ft_connexion_client("127.0.0.1", "4242", fd)) == -1)
			ft_putendl("error connexion");
		while(1)
		{
			ft_client_send_message(fd, "coucou\n");
			ft_client_receive_message(fd, buf);
		}
		close(fd);
	}else
	{
		//gerer auqnd un client se deconnecte
		ft_putendl("server");
		ft_init_server(&server);
		fd = ft_socket_serveur(0, &server);
		if (fd == -1)
			ft_putendl("error socket server");
		if ((ft_init_serveur("127.0.0.1", "4242", &server)) == -1)
			ft_putendl("Erreur init server");
		while (1)
		{
			ft_check_sockets(&server);
			//ft_accept_connection(&server);
			//ft_server_send_message(&server, "mouhahahahha");
			ft_server_receive_message_all(&server, buf);
		}
		close(fd);
	}
	return (0);
}
