/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parse_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:25:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 14:26:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		object_parse_command_execute(t_env *env, t_object *object
		, struct load_command *load_command)
{
	if (load_command->cmd == LC_SYMTAB)
		return (object_parse_command_symtab(env, object));
	else if (load_command->cmd == LC_SEGMENT)
		return (object_parse_command_segment_32(object));
	else if (load_command->cmd == LC_SEGMENT_64)
		return (object_parse_command_segment_64(object));
	return (1);
}

static int		object_parse_load_command(t_object *object
		, struct load_command *load_command)
{
	if (!buffer_read(&object->buffer, load_command
				, sizeof(load_command)))
		return (0);
	if (!buffer_set_position(&object->buffer, object->buffer.position
				- sizeof(*load_command)))
		return (0);
	return (1);
}

static int		object_parse_command(t_env *env, t_object *object)
{
	struct load_command	load_command;
	size_t				buff_pos;

	if (!object_parse_load_command(object, &load_command))
		return (0);
	buff_pos = object->buffer.position;
	if (!object_parse_command_execute(env, object, &load_command))
		return (0);
	if (!buffer_set_position(&object->buffer, buff_pos
					+ load_command.cmdsize))
		return (0);
	return (1);
}

int				object_parse_commands(t_env *env, t_object *object)
{
	uint32_t	i;

	i = 0;
	while (i < object->header.ncmds)
	{
		if (!object_parse_command(env, object))
			return (0);
		i++;
	}
	return (1);
}
