/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_section_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:30:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:11:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	struct_section_read_32(t_object *object, t_section *section)
{
	struct section		ssection;

	if (!buffer_read(&object->buffer, &ssection, sizeof(ssection)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_section_reverse_32(&ssection);
	ft_memcpy(section->sectname, ssection.sectname, sizeof(section->sectname));
	ft_memcpy(section->segname, ssection.segname, sizeof(section->segname));
	section->addr = ssection.addr;
	section->size = ssection.size;
	section->offset = ssection.offset;
	section->align = ssection.align;
	section->reloff = ssection.reloff;
	section->nreloc = ssection.nreloc;
	section->flags = ssection.flags;
	return (1);
}

int	struct_section_read_64(t_object *object, t_section *section)
{
	struct section_64	ssection;

	if (!buffer_read(&object->buffer, &ssection, sizeof(ssection)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_section_reverse_64(&ssection);
	ft_memcpy(section->sectname, ssection.sectname, sizeof(section->sectname));
	ft_memcpy(section->segname, ssection.segname, sizeof(section->segname));
	section->addr = ssection.addr;
	section->size = ssection.size;
	section->offset = ssection.offset;
	section->align = ssection.align;
	section->reloff = ssection.reloff;
	section->nreloc = ssection.nreloc;
	section->flags = ssection.flags;
	return (1);
}
