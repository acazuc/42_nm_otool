/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_segments_push_back.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:55:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 10:45:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		object_segments_push_back(t_segment_list **list, t_segment segment)
{
	t_segment_list	*new;
	t_segment_list	*tmp;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->segment = segment;
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		return (1);
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}
