/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:26:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		get_section_letter_result(char *section)
{
	if (!ft_strcmp(section, SECT_TEXT))
		return ('T');
	if (!ft_strcmp(section, SECT_BSS))
		return ('B');
	if (!ft_strcmp(section, SECT_DATA))
		return ('D');
	return ('S');
}

static char		get_section_letter(t_object *object, uint8_t section)
{
	t_segment_list	*seg;
	t_section_list	*sec;
	int16_t			i;

	i = 0;
	seg = object->segments;
	while (seg)
	{
		sec = seg->segment.sections;
		while (sec)
		{
			if (++i == section)
				return (get_section_letter_result(sec->section.sectname));
			sec = sec->next;
		}
		seg = seg->next;
	}
	return ('U');
}

static void		print_object_letter(t_object *object, t_symbol *symbol)
{
	char c;

	if (symbol->type & N_STAB)
		c = '-';
	else
		c = get_section_letter(object, symbol->sect);
	if (!(symbol->type & N_EXT) && c >= 'A' && c <= 'Z')
		c -= 'A' - 'a';
	ft_putchar(c);
}

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
		print_object_letter(object, &lst->symbol);
		ft_putchar(' ');
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
