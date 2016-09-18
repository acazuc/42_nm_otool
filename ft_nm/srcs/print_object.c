/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 14:42:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		get_section_letter(t_object *object, uint8_t section)
{
	t_section_list	*lst;
	uint8_t			i;

	i = 1;
	lst = object->sections;
	while (lst)
	{
		if (i == section)
		{
			if (!ft_strcmp(lst->section.name, SECT_TEXT))
				return ('T');
			if (!ft_strcmp(lst->section.name, SECT_BSS))
				return ('B');
			if (!ft_strcmp(lst->section.name, SECT_DATA))
				return ('D');
			else
				return ('S');
		}
		i++;
		lst = lst->next;
	}
	return ('U');
}

static void		print_object_letter(t_object *object, t_symbol *symbol)
{
	if (symbol->section == 0)
	{
		ft_putchar('U');
		return ;
	}
	ft_putchar(get_section_letter(object, symbol->section));
}

void			print_object(t_object *object)
{
	t_symbol_list	*lst;

	lst = object->symbols;
	while (lst)
	{
		if (object->is_64)
			print_hex_8(lst->symbol.value);
		else
			print_hex_4(lst->symbol.value);
		ft_putchar(' ');
		print_object_letter(object, &lst->symbol);
		ft_putchar(' ');
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
