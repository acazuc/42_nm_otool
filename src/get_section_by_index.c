/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section_by_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:54:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:06:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_section	*get_section_by_index(t_segment_list *list, uint8_t index)
{
	t_segment_list	*seg;
	t_section_list	*sec;
	int16_t			i;

	i = 0;
	seg = list;
	while (seg)
	{
		sec = seg->segment.sections;
		while (sec)
		{
			if (++i == index)
				return (&sec->section);
			sec = sec->next;
		}
		seg = seg->next;
	}
	return (NULL);
}
