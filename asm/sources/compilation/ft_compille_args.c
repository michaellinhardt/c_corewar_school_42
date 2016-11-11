/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compille_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:31 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:18:31 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_asm.h"

int			ft_compile_register(t_parse_tree *tree, unsigned char *code)
{
	char	*registre;

	registre = tree->token->value;
	++registre;
	*code = *registre - 48;
	if (*(++registre))
		*code = (*registre - 48) + *code * 10;
	return (1);
}

int			ft_compile_direct(t_parse_tree *tree, unsigned char *code,
		int flag_dir)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;
	unsigned int size;

	nbr = ft_atoi(tree->token->value + 1);
	if (flag_dir)
	{
		nbr = (unsigned short)nbr;
		size = 2;
	}
	else
		size = 4;
	decal = (size - 1) * 8;
	i = 0;
	while (i < size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (size);
}

int			ft_compile_direct_label(t_parse_tree *tree, unsigned char *code,
		int flag_dir)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;
	unsigned int size;

	nbr = tree->position;
	if (flag_dir)
	{
		nbr = (unsigned short)nbr;
		size = 2;
	}
	else
		size = 4;
	decal = (size - 1) * 8;
	i = 0;
	while (i < size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (size);
}

int			ft_compile_indirect(t_parse_tree *tree, unsigned char *code)
{
	unsigned int nbr;
	unsigned int i;
	unsigned int decal;
	unsigned int size;

	nbr = ft_atoi(tree->token->value);
	nbr = (unsigned short)nbr;
	size = 2;
	decal = (size - 1) * 8;
	i = 0;
	while (i < size)
	{
		*(code + i) = nbr >> decal;
		decal -= 8;
		++i;
	}
	return (size);
}
