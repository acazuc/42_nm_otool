/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:24:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 13:24:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	object_parse_magic(t_object *object)
{
	uint32_t	magic;

	if (!buffer_read(&object->buffer, &object->header.magic
					, sizeof(object->header.magic)))
		return (0);
	if (!buffer_set_position(&object->buffer, 0))
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

int			object_parse(t_env *env, t_object *object)
{
	object->segments = NULL;
	object->symbols = NULL;
	if (!object_parse_magic(object))
		return (0);
	if (!struct_object_header_read(object, &object->header))
		return (0);
	if (!object_parse_commands(env, object))
		return (0);
	if (env->params.r)
		struct_symbol_list_reverse(&object->symbols);
	return (1);
}
