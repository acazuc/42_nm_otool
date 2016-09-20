/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:05:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void			print_object(t_object *object)
{
	t_symbol_list	*lst;

	lst = object->symbols;
	while (lst)
	{
		if (lst->symbol.sect == 0)
		{
			if (object->is_64)
				ft_putstr("                ");
			else
				ft_putstr("        ");
		}
		else
		{
			if (object->is_64)
				print_hex_8(lst->symbol.value);
			else
				print_hex_4(lst->symbol.value);
		}
		ft_putchar(' ');
		ft_putchar(get_symbol_letter(object, &lst->symbol));
		ft_putchar(' ');
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
