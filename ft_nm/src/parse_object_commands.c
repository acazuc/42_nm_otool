/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:25:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:19:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		parse_object_command_execute(t_object *object
		, struct load_command *load_command)
{
	if (load_command->cmd == LC_SYMTAB)
		return (parse_object_command_symtab(object));
	else if (load_command->cmd == LC_SEGMENT)
		return (parse_object_command_segment_32(object));
	else if (load_command->cmd == LC_SEGMENT_64)
		return (parse_object_command_segment_64(object));
	return (1);
}

static int		parse_object_load_command(t_object *object
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

static int		parse_object_command(t_object *object)
{
	struct load_command	load_command;
	size_t				buff_pos;

	if (!parse_object_load_command(object, &load_command))
		return (0);
	buff_pos = object->buffer.position;
	if (!parse_object_command_execute(object, &load_command))
		return (0);
	if (!buffer_set_position(&object->buffer, buff_pos
					+ load_command.cmdsize))
		return (0);
	return (1);
}

int				parse_object_commands(t_object *object)
{
	uint32_t	i;

	i = 0;
	while (i < object->header.ncmds)
	{
		if (!parse_object_command(object))
			return (0);
		i++;
	}
	return (1);
}
