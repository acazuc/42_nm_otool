/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 08:47:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		get_section_letter(t_object *object, uint8_t section)
{
	t_section_list	*lst;
	int16_t			i;

	i = 0;
	lst = object->sections;
	while (lst)
	{
		if (++i == section)
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
		lst = lst->next;
	}
	return ('U');
}

static void		print_object_letter(t_object *object, t_symbol *symbol)
{
	char c;

	c = get_section_letter(object, symbol->section);
	if (!symbol->external)
		c -= 'A' - 'a';
	ft_putchar(c);
}

void			print_object(t_object *object)
{
	t_symbol_list	*lst;

	lst = object->symbols;
	while (lst)
	{
		if (lst->symbol.section == 0)
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
		print_object_letter(object, &lst->symbol);
		ft_putchar(' ');
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
