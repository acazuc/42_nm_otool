/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:03:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 11:01:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		archive_print_file(t_archive *archive, t_ar_file *file)
{
	if (!parse_object(&file->object))
		return ;
	ft_putchar('\n');
	ft_putstr(archive->file->name);
	ft_putchar('(');
	ft_putstr(file->name);
	ft_putendl("):");
	print_object(&file->object);
}

static int		check_reorder_symdef(t_archive *archive)
{
	t_ar_file_list	*lst;

	lst = archive->files;
	while (lst)
	{
		if (!ft_strcmp(lst->file.name, SYMDEF_SORTED))
		{
			if (!archive_parse_symdef(archive, &lst->file))
				return (0);
			return (1);
		}
		lst = lst->next;
	}
	return (1);
}

void			archive_print(t_archive *archive)
{
	t_ar_file_list	*lst;

	if (!check_reorder_symdef(archive))
		return ;
	lst = archive->files;
	while (lst)
	{
		if (ft_strcmp(lst->file.name, SYMDEF)
				&& ft_strcmp(lst->file.name, SYMDEF_SORTED))
			archive_print_file(archive, &lst->file);
		lst = lst->next;
	}
}