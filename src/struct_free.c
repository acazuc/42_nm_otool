/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 08:39:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 13:22:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	struct_fat_free(t_fat *fat)
{
	t_fat_file_list	*file_lst;
	t_fat_file_list	*file_nxt;

	file_lst = fat->files;
	while (file_lst)
	{
		file_nxt = file_lst->next;
		free(file_lst);
		file_lst = file_nxt;
	}
}

void	struct_archive_free(t_archive *archive)
{
	t_ar_file_list	*file_lst;
	t_ar_file_list	*file_nxt;

	file_lst = archive->files;
	while (file_lst)
	{
		file_nxt = file_lst->next;
		free(file_lst);
		file_lst = file_nxt;
	}
}

void	struct_object_free(t_object *object)
{
	t_segment_list	*segments_lst;
	t_segment_list	*segments_nxt;

	segments_lst = object->segments;
	while (segments_lst)
	{
		segments_nxt = segments_lst->next;
		struct_segment_free(segments_lst);
		segments_lst = segments_nxt;
	}
}

void	struct_segment_free(t_segment_list *segment)
{
	t_section_list	*sections_lst;
	t_section_list	*sections_nxt;

	sections_lst = segment->segment.sections;
	while (sections_lst)
	{
		sections_nxt = sections_lst->next;
		struct_section_free(sections_lst);
		sections_lst = sections_nxt;
	}
	free(segment);
}

void	struct_section_free(t_section_list *section)
{
	free(section);
}
