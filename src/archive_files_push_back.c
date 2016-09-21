/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_object_list_push_back.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 08:40:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 15:15:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		archive_files_push_back(t_ar_file_list **list, t_ar_file file)
{
	t_ar_file_list	*new;
	t_ar_file_list	*tmp;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->file = file;
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
