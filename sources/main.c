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


// faire une static pour plus tard
// signaux  gerer dans le programme principal
void		ft_sigint(int sig)
{
	char interrupt;

	interrupt = 3;
	ft_putendl("interrupr programme");
	close(sig);
	ioctl(0, TIOCSTI, &interrupt);
	signal(SIGINT, SIG_DFL);
}



// rendre le code plus propre, envoi nom champoin lors de laconnexion,
// ajouter une surcouche du code pour une integration simplifie
int		main(int argc, char **argv)
{
	signal(SIGINT, ft_sigint);
	signal(SIGPIPE, SIG_IGN);

	(void)argv;
	int fd;

	char buf[BUFF_SIZE];
	int ret;
	fd = -1;
	t_server server;
	t_client client;

	//gerer les signaux pour close le fd lors d'un ctl c kill ctrl d
	//voir pur utiliser un keep-alive pour les clients

	if (argc > 1)
	{
		// on seras client -> pour les tests
		ft_putendl("Client");
		ft_client_init(&client, argv[1]);
		fd = ft_client_socket(0, &client);
		if (fd == -1)
			ft_putendl("error fd");
		if ((ft_client_connexion(argv[2], "4242", &client)) == -1)
			ft_putendl("error connexion");
		ft_strcpy(client.data_send.name, argv[1]);
		ft_putendl(client.data_send.name);
		while(1)
		{
			ret = ft_client_check_read_sockets(&client);
			if (ret == 2)
			{
				ft_putendl("programme exit");
				break ;
			}
			client.data_send.nbr++;
			ft_client_send_message(&client, "i'm alive\n");
			//ft_client_receive_message(fd, buf);
		}
		close(fd);
	}else if (argc == 1)
	{
		//gerer auqnd un client se deconnecte
		ft_putendl("server");
		//ft_init_server(&server);

		ft_init_struct_server(&server, "lol");
		fd = ft_socket_serveur(0, &server);
		if (fd == -1)
			ft_putendl("error socket server");
		if ((ft_init_server("127.0.0.1", "4242", &server, "KIKI")) == -1)
			ft_putendl("Erreur init server");
		while (1)
		{
		ret = 	ft_server_check_read_sockets(&server);
		if (ret == 2)
		{
			ft_putendl("programme exit");
			break ;
		}
		//ft_print_memory(server.name, (sizeof(server.name)));
			//ft_accept_connection(&server);
			if ((ft_server_send_message_all(&server, "mouhahahahha") == -1))
				break ;
			//ft_server_receive_message_all(&server, buf);
		}
		ft_server_disconnect_client_all(&server);
		close(fd);
	}
	ft_putendl("the end");
	return (0);
}
