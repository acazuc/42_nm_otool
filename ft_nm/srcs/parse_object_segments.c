/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_segments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:25:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 12:24:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		parse_object_segment_command_2(t_object *object, t_object_cmd *object_cmd)
{
	if (object_cmd->load_command.cmd == LC_SYMTAB)
		return (parse_object_command_symtab(object, object_cmd));
	return (1);
}

static int		parse_object_segment_command(t_object *object)
{
	t_object_cmd	object_cmd;

	if (!buffer_read(&object->buffer, &object_cmd.load_command, sizeof(object_cmd.load_command)))
		return (0);
	if (!buffer_set_position(&object->buffer, object->buffer.position - sizeof(object_cmd.load_command)))
		return (0);
	ft_putstr("Command id: ");
	ft_putnbr(object_cmd.load_command.cmd);
	ft_putstr(", Command size: ");
	ft_putnbr(object_cmd.load_command.cmdsize);
	ft_putchar('\n');
	if (!(object_cmd.data = malloc(sizeof(*object_cmd.data) * object_cmd.load_command.cmdsize)))
		return (0);
	if (!buffer_read(&object->buffer, object_cmd.data, object_cmd.load_command.cmdsize))
	{
		free(object_cmd.data);
		return (0);
	}
	if (!parse_object_segment_command_2(object, &object_cmd))
	{
		free(object_cmd.data);
		return (0);
	}
	free(object_cmd.data);
	return (1);
}

int				parse_object_segments(t_object *object)
{
	uint32_t	segment_numbers;
	uint32_t	i;

	segment_numbers = object->is_64 ? object->header.header_64.ncmds : object->header.header_32.ncmds;
	i = 0;
	while (i < segment_numbers)
	{
		if (!parse_object_segment_command(object))
			return (0);
		i++;
	}
	return (1);
}
