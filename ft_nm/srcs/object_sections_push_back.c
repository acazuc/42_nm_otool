/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sections_push_back.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:55:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 14:41:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		object_sections_push_back(t_section_list **list, t_section section)
{
	t_section_list	*new;
	t_section_list	*tmp;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->section = section;
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
