/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:24:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 10:12:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	parse_object_magic(t_object *object)
{
	uint32_t	magic;

	if (!(buffer_read(&object->buffer, &object->header.magic, sizeof(object->header.magic))))
		return (0);
	magic = object->header.magic;
	if (magic != MH_MAGIC && magic != MH_MAGIC_64 && magic != MH_CIGAM && magic != MH_CIGAM_64)
		return (0);
	object->is_64 = magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
	object->byte_order = magic == MH_MAGIC || magic == MH_MAGIC_64 ? BO_BIG : BO_LITTLE;
	return (1);
}

static int	parse_object_header(t_object *object)
{
	size_t	header_size;

	if (object->is_64)
		header_size = sizeof(object->header.header_64);
	else
		header_size = sizeof(object->header.header_32);
	header_size -= 4;
	if (!(buffer_read(&object->buffer, (void*)&object->header.header_64 + sizeof(object->header.magic), header_size)))
		return (0);
	return (1);
}

int		parse_object(t_object *object)
{
	if (!(parse_object_magic(object)))
		return (0);
	ft_putendl(object->is_64 ? "64" : "32");
	ft_putendl(object->byte_order == BO_LITTLE ? "Little Endian" : "Big Endian");
	if (!(parse_object_header(object)))
		return (0);
	uint32_t filetype = object->header.header_32.filetype;
	if (filetype & MH_OBJECT)
		ft_putendl("MH_OBJECT");
	if (filetype & MH_EXECUTE)
		ft_putendl("MH_EXECUTE");
	if (filetype & MH_FVMLIB)
		ft_putendl("MH_FVMLIB");
	if (filetype & MH_CORE)
		ft_putendl("MH_CORE");
	if (filetype & MH_PRELOAD)
		ft_putendl("MH_PRELOAD");
	if (filetype & MH_DYLIB)
		ft_putendl("MH_DYLIB");
	if (filetype & MH_BUNDLE)
		ft_putendl("MH_BUNDLE");
	if (filetype & MH_DYLIB_STUB)
		ft_putendl("MH_DYLIB_STUB");
	if (filetype & MH_DSYM)
		ft_putendl("MH_DSYM");
	if (filetype & MH_KEXT_BUNDLE)
		ft_putendl("MH_KEXT_BUNDLE");
	return (1);
}
