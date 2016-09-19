/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_files_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:20:11 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 15:24:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		fat_files_push_back(t_fat *fat, t_fat_file fat_file)
{
	t_fat_file_list	*lst;
	t_fat_file_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->next = NULL;
	new->file = fat_file;
	if (!fat->files)
	{
		fat->files = new;
		return (1);
	}
	lst = fat->files;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	return (1);
}
