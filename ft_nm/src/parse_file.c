/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:35:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 16:06:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		parse_file_is_archive(t_file *file)
{
	char	magic[8];

	if (!(buffer_read(&file->buffer, magic, 8)))
	{
		ft_putendl("Failed to read archive header");
		return (0);
	}
	if (ft_memcmp(magic, "!<arch>\n", 8))
	{
		buffer_set_position(&file->buffer, 0);
		return (0);
	}
	return (1);
}

static int		parse_file_is_fat(t_file *file)
{
	uint32_t	magic;

	if (!(buffer_read(&file->buffer, &magic, 8)))
	{
		ft_putendl("Failed to read fat header");
		return (0);
	}
	if (magic == FAT_MAGIC || magic == FAT_CIGAM)
	{
		return (1);
	}
	buffer_set_position(&file->buffer, 0);
	return (0);
}

static void		parse_file_file(t_file *file)
{
	t_object object;

	object.buffer = file->buffer;
	if (!(parse_object(&object)))
		return ;
	print_object(&object);
}

void			parse_file(t_file *file, int print_name)
{
	if (parse_file_is_archive(file))
	{
		if (!parse_archive(file))
			ft_putendl_fd("Invalid archive", 2);
		return ;
	}
	if (print_name)
	{
		ft_putchar('\n');
		ft_putstr(file->name);
		ft_putendl(":");
	}
	if (parse_file_is_fat(file))
	{
		if (!(parse_fat(file)))
			ft_putendl_fd("Invalid fat", 2);
		return ;
	}
	parse_file_file(file);
}
