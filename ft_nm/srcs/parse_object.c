/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:24:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 09:38:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	parse_object_magic(t_object *object)
{
	uint32_t magic;

	if (!(buffer_read(&object->buffer, &object->header.magic, 4)))
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
	
}

int		parse_object(t_object *object)
{
	if (!(parse_object_magic(object)))
		return (0);
	ft_putendl(object->is_64 ? "64" : "32");
	ft_putendl(object->byte_order == BO_LITTLE ? "Little Endian" : "Big Endian");
	if (!(parse_object_header(object)))
		return (0);
	uint32_t magic = object->header.magic;
	if (magic & MH_OBJECT)
		ft_putendl("MH_OBJECT");
	if (magic & MH_EXECUTE)
		ft_putendl("MH_EXECUTE");
	if (magic & MH_DYLIB)
		ft_putendl("DYLIB");
	if (magic & MH_DYLIB_STUB)
		ft_putendl("MH_DYLIB_STUB");
	return (1);
}
