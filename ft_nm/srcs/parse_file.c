/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:35:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 10:12:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		parse_file_is_archive(t_file *file)
{
	char magic[8];

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

static void		parse_file_file(t_file *file)
{
	t_object object;

	object.buffer = file->buffer;
	if (!(parse_object(&object)))
		return ;
}

void			parse_file(t_file *file)
{
	if (parse_file_is_archive(file))
	{
		ft_putendl("Static archive file");
		parse_archive(file);
		return ;
	}
	parse_file_file(file);
}
