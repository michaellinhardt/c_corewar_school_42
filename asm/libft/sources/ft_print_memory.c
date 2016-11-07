/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 15:34:12 by abary             #+#    #+#             */
/*   Updated: 2016/07/19 16:04:54 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SIZE 17

static void	ft_puthex(unsigned char c)
{
	if (c / 16)
		ft_puthex(c / 16);
	if (c % 16 >= 10)
	{
		ft_putchar(87 + c % 16);
	}
	else
		ft_putchar(48 + c % 16);
}

static void	ft_printhex(unsigned char *str, size_t size, size_t total)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (*(str + i) < 16)
			ft_putchar('0');
		ft_puthex(*(str + i));
		if (i % 2)
			ft_putchar(' ');
		++i;
	}
	while (i < total)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2)
			ft_putchar(' ');
		++i;
	}
}

static void	ft_printf_ascii(unsigned char *str, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (*(str + i) >= 040 && *(str + i) <= 0176)
			ft_putchar(*(str + i));
		else
			ft_putchar('.');
		++i;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t			i;
	unsigned char	put[SIZE];
	size_t			end;

	i = 0;
	ft_bzero(put, SIZE);
	while (i < size)
	{
		put[i % 16] = *((unsigned char *)addr + i);
		++i;
		if (!(i % 16))
		{
			ft_printhex(put, SIZE - 1, SIZE - 1);
			ft_printf_ascii(put, SIZE - 1);
			ft_bzero(put, SIZE);
			ft_putchar('\n');
		}
	}
	if ((i % 16))
	{
		end = SIZE - 1 - (i % 16);
		ft_printhex(put, i % 16, SIZE - 1);
		ft_printf_ascii(put, i % 16);
		ft_putchar('\n');
	}
}
