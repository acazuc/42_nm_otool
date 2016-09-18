/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_symbols_push_back.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:27:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 14:30:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		object_symbols_push_back(t_symbol_list **list, t_symbol symbol)
{
	t_symbol_list	*new;
	t_symbol_list	*tmp;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->symbol = symbol;
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		return (1);
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}
