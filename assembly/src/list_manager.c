/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 02:35:28 by pba               #+#    #+#             */
/*   Updated: 2016/09/04 04:28:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token				*token_new(e_kind kind, int value)
{
	t_token			*token;

	if ((token = (t_token *)malloc(sizeof(t_token))))
	{
		ft_memset(token, 0, sizeof(t_token));
		token->kind = kind;
		token->value = value;
	}
	return (token);
}

t_tlist				*list_new()
{
	t_tlist			*list;

	if ((list = (t_tlist *)malloc(sizeof(t_tlist))))
		ft_memset(list, 0, sizeof(t_tlist));
	return (list);
}

t_tlist				*list_append(t_tlist *list, e_kind kind, int value)
{
	t_token			*newtoken;

	newtoken = token_new(kind, value);
	if (list && newtoken)
	{
		if (list->head == NULL)
		{
			list->head = newtoken;
			newtoken->prev = list->head;
			newtoken->next = list->head;
		}
		else
		{
			newtoken->next = list->head;
			newtoken->prev = list->head->prev;
			list->head->prev->next = newtoken;
			list->head->prev = newtoken;
		}
		++list->size;
	}
	return (list);
}

/*t_dlist				*dlist_prepend(t_dlist *list, enum kind, int value)
{
	t_dcell			*newcell;

	newcell = dcell_new(kind, value);
	if (list && newcell)
	{
		if (list->head == NULL)
		{
			list->head = newcell;
			newcell->prev = list->head;
			newcell->next = list->head;
		}
		else
		{
			newcell->next = list->head;
			newcell->prev = list->head->prev;
			list->head->prev->next = newcell;
			list->head->prev = newcell;
			newcell = list->head;
		}
		++list->size;
	}
	return (list);
}*/

void				list_display(t_tlist *list)
{
	t_token			*tmp;

	if (list->head == NULL || list->size == 0)
		return ;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		ft_putnbr(tmp->kind);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putnbr(tmp->kind);
}
