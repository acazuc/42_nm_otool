/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:03:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 09:45:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	archive_print_file(t_archive *archive, t_ar_file *file)
{
	if (!parse_object(&file->object))
		return ;
	ft_putstr(archive->file->name);
	ft_putchar('(');
	ft_putstr(file->name);
	ft_putendl("):");
}

void	archive_print(t_archive *archive)
{
	t_ar_file_list *lst;

	lst = archive->files;
	while (lst)
	{
		archive_print_file(archive, &lst->file);
		lst = lst->next;
	}
}
