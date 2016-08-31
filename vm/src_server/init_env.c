/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:56:22 by pba               #+#    #+#             */
/*   Updated: 2016/08/25 21:59:34 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
/*
** this function initialize my env structure.
*/

t_env					*init_env(char **env)
{
	t_env				*serv_env;

	if ((serv_env = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	serv_env->env = env;
	ft_memset((void*)&serv_env->result, 0, sizeof(t_result));
	return (serv_env);
}
