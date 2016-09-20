/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_command_segment.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:13:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:21:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	parse_object_command_segment(t_object *object
		, int (*struct_segment_read)(t_object *object, t_segment *segment)
		, int (*struct_section_read)(t_object *object, t_section *section))
{
	t_segment					segment;
	t_section					section;
	uint32_t					i;

	if (!struct_segment_read(object, &segment))
		return (0);
	segment.sections = NULL;
	i = 0;
	while (i < segment.nsects)
	{
		if (!struct_section_read(object, &section))
			return (0);
		if (!segment_sections_push_back(&segment.sections, section))
			return (0);
		i++;
	}
	object_segments_push_back(&object->segments, segment);
	return (1);
}

int			parse_object_command_segment_32(t_object *object)
{
	return (parse_object_command_segment(object
				, struct_segment_read_32
				, struct_section_read_32));
}

int			parse_object_command_segment_64(t_object *object)
{
	return (parse_object_command_segment(object
				, struct_segment_read_64
				, struct_section_read_64));
}
