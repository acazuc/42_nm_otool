/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_symbols_push_back.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:27:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 09:44:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		swap(t_symbol_list *new, t_symbol_list *lst, t_symbol_list *prv
		, t_symbol_list **list)
{
	new->next = lst;
	if (prv)
		prv->next = new;
	else
		(*list) = new;
}

static void		insert(t_symbol_list **list, t_symbol_list *new)
{
	t_symbol_list		*prv;
	t_symbol_list		*lst;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	lst = *list;
	prv = NULL;
	while (lst)
	{
		if (ft_strcmp(lst->symbol.name, new->symbol.name) >= 0)
		{
			swap(new, lst, prv, list);
			return ;
		}
		if (!lst->next)
		{
			lst->next = new;
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}

int				object_symbols_push_back(t_symbol_list **list, t_symbol symbol)
{
	t_symbol_list		*new;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	if (symbol.name == NULL)
		if (!(symbol.name = ft_strdup("")))
			return (0);
	new->symbol = symbol;
	new->next = NULL;
	insert(list, new);
	return (1);
}
