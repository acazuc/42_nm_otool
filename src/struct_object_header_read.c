/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_object_header_read.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 08:28:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 13:53:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	struct_object_header_read_32(t_object *object
		, t_object_header *object_header)
{
	struct mach_header		mach_header;

	if (!buffer_read(&object->buffer, &mach_header, sizeof(mach_header)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_mach_header_reverse_32(&mach_header);
	object_header->magic = mach_header.magic;
	object_header->cputype = mach_header.cputype;
	object_header->cpusubtype = mach_header.cpusubtype;
	object_header->ncmds = mach_header.ncmds;
	object_header->sizeofcmds = mach_header.sizeofcmds;
	object_header->flags = mach_header.flags;
	return (1);
}

static int	struct_object_header_read_64(t_object *object
		, t_object_header *object_header)
{
	struct mach_header_64	mach_header;

	if (!buffer_read(&object->buffer, &mach_header, sizeof(mach_header)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_mach_header_reverse_64(&mach_header);
	object_header->magic = mach_header.magic;
	object_header->cputype = mach_header.cputype;
	object_header->cpusubtype = mach_header.cpusubtype;
	object_header->ncmds = mach_header.ncmds;
	object_header->sizeofcmds = mach_header.sizeofcmds;
	object_header->flags = mach_header.flags;
	return (1);
}

int			struct_object_header_read(t_object *object
		, t_object_header *object_header)
{
	if (object->is_64)
		return (struct_object_header_read_64(object, object_header));
	return (struct_object_header_read_32(object, object_header));
}
