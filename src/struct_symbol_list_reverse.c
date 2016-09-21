/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_symbol_list_reverse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:46:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 15:50:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	struct_symbol_list_reverse(t_symbol_list **list)
{
	t_symbol_list *lst;
	t_symbol_list *tmp;
	t_symbol_list *prv;

	prv = NULL;
	lst = *list;
	while (lst)
	{
		tmp = lst->next;
		lst->next = prv;
		prv = lst;
		lst = tmp;
	}
	*list = prv;
}
