/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 00:55:43 by pba               #+#    #+#             */
/*   Updated: 2016/08/31 18:21:11 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/stat.h>
# include <sys/time.h>
# include "op.h"
# include "libft.h"
# define FIELDSIZE		(0x1000)
# define CODESIZE		(0xff)
# define CODEITEM		(0)
# define CODE_INIT(x, y, z) x = y; ft_bzero((void *)&y, z);

enum kind {TEXT, NUMBER};
typedef struct protoent	t_protoent;
typedef struct addrinfo	t_addrinfo;
typedef struct			s_result
{
	int					code_return;
	int					client;
}						t_result;
typedef struct			s_env
{
	int					cs;
	char				**env;
	t_result			result;
}						t_env;
typedef struct			s_arena
{
	char				name[256];
	char				field[FIELDSIZE];
}						t_arena;
typedef struct			s_token
{
	enum kind			kind;
	int					value;
}						t_token;
int						create_server(char *port);
int						create_client(char *addr, char *port);
t_env					*init_env(char **env);
void					request(t_env *serv_env, int sock, char *buf);
void					parser(t_env *serv_env, char *line);
int						check_champion(char *path);
t_result				*read_until_notif(int socket_read, int socket_write);

#endif
