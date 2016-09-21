/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 09:03:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 13:18:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		archive_print_file_trunc(char *str)
{
	size_t	i;

	if (ft_strlen(str) == 0)
		return ;
	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] == ' ')
	{
		--i;
	}
	str[i + 1] = '\0';
}

static void		archive_print_file_header(t_ar_file_header *header)
{
	ft_putchar('0');
	archive_print_file_trunc(header->mode);
	ft_putstr(header->mode);
	ft_putchar(' ');
	archive_print_file_trunc(header->owner_id);
	ft_putstr(header->owner_id);
	ft_putchar('/');
	archive_print_file_trunc(header->group_id);
	ft_putstr(header->group_id);
	ft_putstr("  ");
	archive_print_file_trunc(header->size);
	ft_putstr(header->size);
	ft_putchar(' ');
	archive_print_file_trunc(header->modif_ts);
	ft_putstr(header->modif_ts);
	ft_putchar(' ');
	archive_print_file_trunc(header->identifier);
	ft_putstr(header->identifier);
	ft_putchar('\n');
}

static void		archive_print_file(t_env *env, t_archive *archive
		, t_ar_file *file)
{
	char	fname[ft_strlen(archive->file->name) + ft_strlen(file->name) + 3];

	ft_bzero(fname, sizeof(fname));
	ft_putstr(archive->file->name);
	ft_putchar('(');
	ft_putstr(file->name);
	ft_putendl("):");
	ft_strcat(fname, archive->file->name);
	ft_strcat(fname, ":");
	ft_strcat(fname, file->name);
	ft_strcat(fname, ":");
	object_print(env, &file->object, fname);
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

void			archive_print(t_env *env, t_archive *archive, int a)
{
	t_ar_file_list	*lst;

	(void)a;
	ft_putstr("Archive : ");
	ft_putendl(archive->file->name);
	if (!check_reorder_symdef(archive))
		return ;
	lst = archive->files;
	while (lst)
	{
		if (env->params.a)
			archive_print_file_header(&lst->file.header);
		if (ft_strcmp(lst->file.name, SYMDEF)
				&& ft_strcmp(lst->file.name, SYMDEF_SORTED))
		{
			if (env->params.t || env->params.d)
				archive_print_file(env, archive, &lst->file);
		}
		lst = lst->next;
	}
}
