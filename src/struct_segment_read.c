/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_segment_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:53:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:10:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	struct_segment_read_64(t_object *object, t_segment *segment)
{
	struct segment_command_64	command;

	if (!buffer_read(&object->buffer, &command, sizeof(command)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_segment_command_reverse_64(&command);
	segment->cmd = command.cmd;
	segment->cmdsize = command.cmdsize;
	ft_memcpy(segment->segname, command.segname, sizeof(segment->segname));
	segment->vmaddr = command.vmaddr;
	segment->vmsize = command.vmsize;
	segment->fileoff = command.fileoff;
	segment->filesize = command.filesize;
	segment->maxprot = command.maxprot;
	segment->initprot = command.initprot;
	segment->nsects = command.nsects;
	segment->flags = command.flags;
	return (1);
}

int	struct_segment_read_32(t_object *object, t_segment *segment)
{
	struct segment_command		command;

	if (!buffer_read(&object->buffer, &command, sizeof(command)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_segment_command_reverse_32(&command);
	segment->cmd = command.cmd;
	segment->cmdsize = command.cmdsize;
	ft_memcpy(segment->segname, command.segname, sizeof(segment->segname));
	segment->vmaddr = command.vmaddr;
	segment->vmsize = command.vmsize;
	segment->fileoff = command.fileoff;
	segment->filesize = command.filesize;
	segment->maxprot = command.maxprot;
	segment->initprot = command.initprot;
	segment->nsects = command.nsects;
	segment->flags = command.flags;
	return (1);
}
