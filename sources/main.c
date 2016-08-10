#include "libft.h"
#include "client.h"


#include <netdb.h> //gethostbyname
#include <stdio.h> //printf
#include <arpa/inet.h> // inet_ntoa
#include <sys/socket.h> // socke
#include <sys/ioctl.h> // ioctl

int		main(int argc, char **argv)
{

	/*
	** Test
	*/

	/************************************************************
	 **					GEThostbyname
	 **********************************************************/
	/*
	struct hostent *host_name;
	struct in_addr lst_addr;

	host_name = (void *)0;
	host_name = gethostbyname("e1r11p17.42.fr");

	if (host_name)
	{
		printf("h_name :%s\n", host_name->h_name);
		printf("tableau d'aliaes : \n");
		display_map(host_name->h_aliases);
		ft_putchar('\n');
		printf("host address type : %d\n", host_name->h_addrtype);
		printf("lenght of address : %d\n", host_name->h_length);
		printf("List of addresses frome name server\n");

		int i;
		i = 0;
		while (host_name->h_addr_list[i])
		{
				lst_addr.s_addr = *((unsigned long *) host_name->h_addr_list[i++]);
				printf("addresse %s\n", inet_ntoa(lst_addr));
		}
	}
		*/
	/*
	int fd = -1;
	(void)argv;

	fd = socket(PF_INET, SOCK_STREAM , IPPROTO_TCP);
	*/

	/*
	 * Socket en mode non bloquant, sur mac il y a pas le flag SOCK_NONBLOCK
	 */

	/*
	int opt = 1;

 //#define	FIONBIO		_IOW('f', 126, int)	 set/clear non-blocking i/o
	if ((ioctl(fd, FIONBIO, &opt) == -1))
	{
		ft_putendl("Erreur SOCK_NONBLOCK");
		return (0);
	}
	if (fd == -1)
	{
		ft_putendl("Erreur creation Socket");
		return (0);
	}
	*/


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
		fd = ft_socket_serveur(1, &server);
		if (fd == -1)
			ft_putendl("error socket server");
		if ((ft_init_serveur("127.0.0.1", "4242", &server)) == -1)
			ft_putendl("Erreur init server");
		while (1)
		{
			ft_accept_connection(&server);
			ft_server_send_message(&server, "mouhahahahha");
			ft_server_receive_message(&server, buf);
		}
		// on seras serveur -> pour les tests
		//
		close(fd);
	}
	return (0);
}
