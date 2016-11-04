/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:50:25 by abary             #+#    #+#             */
/*   Updated: 2016/05/05 18:23:29 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_words(const char *str)
{
	int nbrwords;

	nbrwords = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			++str;
		if (!*str)
			return (nbrwords);
		while (!ft_isspace(*str))
			++str;
		++nbrwords;
	}
	return (nbrwords);
}

int		ft_words(char **d)
{
	int		size;
	char	**str;

	size = 0;
	str = d;
	while (**d && !ft_isspace(**d))
	{
		++*d;
		++size;
	}
	d = str;
	return (size);
}

char	**ft_strsplit_space(const char *str)
{
	char	**tab;
	int		nbrwords;
	int		nb;
	char	*d;

	nbrwords = ft_nbr_words(str);
	if (!(tab = ft_memalloc(sizeof(char *) * (nbrwords + 1))))
		return (NULL);
	nb = 0;
	d = (char *)str;
	while (nb < nbrwords)
	{
		while (*d && ft_isspace(*d))
			++d;
		tab[nb] = ft_strndup(d, ft_words(&d));
		while (*d && ft_isspace(*d))
			++d;
		ft_putendl(tab[nb]);
		++nb;
	}
	tab[nb] = NULL;
	return (tab);
}
