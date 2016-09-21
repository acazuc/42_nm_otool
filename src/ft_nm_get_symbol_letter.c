/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbol_letter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:04:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:05:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		get_section_letter(t_section *section)
{
	if (!ft_strcmp(section->sectname, SECT_TEXT))
		return ('T');
	if (!ft_strcmp(section->sectname, SECT_BSS))
		return ('B');
	if (!ft_strcmp(section->sectname, SECT_DATA))
		return ('D');
	return ('S');
}

char			get_symbol_letter(t_object *object, t_symbol *symbol)
{
	t_section	*section;
	char		c;

	c = 'U';
	if (symbol->type & N_STAB)
		c = '-';
	else if (symbol->type & N_TYPE & N_SECT)
	{
		c = 'U';
		if ((section = get_section_by_index(object->segments, symbol->sect)))
			c = get_section_letter(section);
	}
	else if (symbol->type & N_TYPE & N_ABS)
		c = 'A';
	if (!(symbol->type & N_EXT) && c >= 'A' && c <= 'Z')
		c -= 'A' - 'a';
	return (c);
}
