/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:23:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void			print_object(t_object *object)
{
	t_symbol_list	*lst;

	lst = object->symbols;
	while (lst)
	{
		print_object_symbol_value(object, &lst->symbol);
		ft_putchar(' ');
		print_object_symbol_sect_letter(object, &lst->symbol);
		ft_putchar(' ');
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
