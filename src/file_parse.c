/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:35:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:49:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		file_parse_archive(t_env *env, t_file *file, int print_name)
{
	t_archive	*archive;
	char		magic[8];

	if (!buffer_read(&file->buffer, magic, 8))
		return (-1);
	if (ft_memcmp(magic, "!<arch>\n", 8))
	{
		if (!buffer_set_position(&file->buffer, 0))
			return (-1);
		return (0);
	}
	if (!(archive = archive_parse(env, file)))
	{
		ft_putendl_fd("Invalid archive", 2);
		return (-1);
	}
	archive_print(env, archive, print_name);
	struct_archive_free(archive);
	return (1);
}

static int		file_parse_fat(t_env *env, t_file *file, int print_name)
{
	t_fat		*fat;
	uint32_t	magic;

	if (!buffer_read(&file->buffer, &magic, 8))
		return (-1);
	if (!buffer_set_position(&file->buffer, 0))
		return (-1);
	if (magic != FAT_MAGIC && magic != FAT_CIGAM)
		return (0);
	if (!(fat = fat_parse(env, file)))
	{
		ft_putendl_fd("Invalid fat", 2);
		return (-1);
	}
	fat_print(env, fat, file, print_name);
	struct_fat_free(fat);
	return (1);
}

static int		file_parse_file(t_env *env, t_file *file, int print_name)
{
	t_object object;

	object.buffer = file->buffer;
	if (!(object_parse(env, &object)))
		return (0);
	file_print(env, file, &object, print_name);
	return (1);
}

void			file_parse(t_env *env, t_file *file, int print_name)
{
	if (file_parse_archive(env, file, print_name))
		return ;
	if (file_parse_fat(env, file, print_name))
		return ;
	if (!file_parse_file(env, file, print_name))
		ft_putendl_fd("Invalid object file", 2);
}
