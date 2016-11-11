/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:42 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:10:42 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	ft_display_help(void)
{
	ft_putendl("  -dump [cycle]\t\tstop at [cycle] and display memory state");
	ft_putendl("  -p \t\t\tforce pause at start");
	ft_putendl("  -n [number 1-4]\tforce next champion number");
	ft_putendl("  -v [number]\t\tlog like zaz to check diff");
	ft_putendl("  -g [number]\t\tforce graphic mode regardless to header");
	ft_putendl("  -l [number]\t\tforce colored log in terminal");
	ft_putendl("  -c [number]\t\trewrite code take proc color");
	ft_putendl("  -m \t\t\tmusic");
	ft_putendl("  -ff7 \t\t\tff7 sound");
	exit(0);
}
