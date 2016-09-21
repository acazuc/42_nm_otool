/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:33:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		object_print_section_do(t_object *object, t_section *section)
{
	uint64_t	pos;
	uint8_t		i;

	ft_putchar('(');
	ft_putstr(section->segname);
	ft_putchar(',');
	ft_putstr(section->sectname);
	ft_putendl(") section");
	pos = 0;
	while (pos < section->buffer.length)
	{
		if (object->is_64)
			print_hex_8(section->addr + pos);
		else
			print_hex_4(section->addr + pos);
		i = -1;
		while (++i < MIN(16, section->buffer.length - pos))
		{
			print_hex_1(*(section->buffer.data + pos + i));
			ft_putchar(' ');
		}
		ft_putchar('\n');
		pos += 16;
	}
}

static void		object_print_section(t_object *object, char *segm, char *sect)
{
	t_segment_list	*seg;
	t_section_list	*sec;

	seg = object->segments;
	while (seg)
	{
		sec = seg->segment.sections;
		while (sec)
		{
			if (!ft_strcmp(sect, sec->section.sectname)
					&& !ft_strcmp(segm, sec->section.segname))
			{
				object_print_section_do(object, &sec->section);
			}
			sec = sec->next;
		}
		seg = seg->next;
	}
}

void			object_print(t_env *env, t_object *object, char *fname)
{
	(void)fname;
	if (env->params.t)
		object_print_section(object, SEG_TEXT, SECT_TEXT);
	else if (env->params.d)
		object_print_section(object, SEG_DATA, SECT_DATA);
}
