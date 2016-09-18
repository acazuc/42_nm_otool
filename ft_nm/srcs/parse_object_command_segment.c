/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_command_segment.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:13:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 14:41:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		parse_object_command_segment_32(t_object *object, t_object_cmd *object_cmd)
{
	return (parse_object_command_segment_64(object, object_cmd));
}

int		parse_object_command_segment_64(t_object *object, t_object_cmd *object_cmd)
{
	struct segment_command_64	segment_command;
	struct section_64			section;
	t_section					sec;
	size_t						offset;
	uint32_t					i;

	ft_memcpy(&segment_command, object_cmd->data, sizeof(segment_command));
	i = 0;
	offset = sizeof(segment_command);
	while (i < segment_command.nsects)
	{
		ft_memcpy(&section, object_cmd->data + offset, sizeof(section));
		sec.name = ft_strdup(section.sectname);
		if (!object_sections_push_back(&object->sections, sec))
			return (0);
		offset += sizeof(section);
		i++;
	}
	return (1);
}
