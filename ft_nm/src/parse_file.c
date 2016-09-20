/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:35:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:17:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		parse_file_is_archive(t_file *file)
{
	char	magic[8];

	if (!buffer_read(&file->buffer, magic, 8))
		return (-1);
	if (ft_memcmp(magic, "!<arch>\n", 8))
	{
		if (!buffer_set_position(&file->buffer, 0))
			return (-1);
		return (0);
	}
	return (1);
}

static int		parse_file_is_fat(t_file *file)
{
	uint32_t	magic;

	if (!buffer_read(&file->buffer, &magic, 8))
		return (-1);
	if (!buffer_set_position(&file->buffer, 0))
		return (-1);
	if (magic != FAT_MAGIC && magic != FAT_CIGAM)
		return (0);
	return (0);
}

static int		parse_file_file(t_file *file)
{
	t_object object;

	object.buffer = file->buffer;
	if (!(parse_object(&object)))
		return (0);
	print_object(&object);
	return (1);
}

void			parse_file(t_file *file, int print_name)
{
	int		ret;

	if ((ret = parse_file_is_archive(file)) == 1)
	{
		if (!parse_archive(file))
			ft_putendl_fd("Invalid archive", 2);
	}
	if (ret)
		return ;
	if (print_name)
	{
		ft_putchar('\n');
		ft_putstr(file->name);
		ft_putendl(":");
	}
	if ((ret = parse_file_is_fat(file)) == 1)
	{
		if (!(parse_fat(file)))
			ft_putendl_fd("Invalid fat", 2);
	}
	if (ret)
		return ;
	if (!parse_file_file(file))
		ft_putendl_fd("Invalid object file", 2);
}
