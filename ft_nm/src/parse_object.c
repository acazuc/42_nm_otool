/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:24:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 14:46:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	parse_object_magic(t_object *object)
{
	uint32_t	magic;

	if (!(buffer_read(&object->buffer, &object->header.magic
					, sizeof(object->header.magic))))
		return (0);
	magic = object->header.magic;
	if (magic != MH_MAGIC && magic != MH_MAGIC_64 && magic != MH_CIGAM
			&& magic != MH_CIGAM_64)
		return (0);
	object->is_64 = magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
	object->byte_order = magic == MH_MAGIC || magic == MH_MAGIC_64
		? BO_BIG : BO_LITTLE;
	return (1);
}

static int	parse_object_header(t_object *object)
{
	size_t	header_size;

	header_size = get_object_header_size(object);
	if (!(buffer_read(&object->buffer, (void*)&object->header.header_64
					+ sizeof(object->header.magic)
					, header_size - sizeof(object->header.magic))))
		return (0);
	return (1);
}

int			parse_object(t_object *object)
{
	object->sections = NULL;
	object->symbols = NULL;
	if (!(parse_object_magic(object)))
		return (0);
	if (!(parse_object_header(object)))
		return (0);
	if (!parse_object_segments(object))
		return (0);
	return (1);
}
