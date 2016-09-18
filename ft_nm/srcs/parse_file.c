/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:35:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 07:35:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		parse_file_is_archive(t_file *file)
{
	char magic[8];
	if (!(buffer_read(&file->buffer, magic, 8)))
	{
		ft_putendl("Failed to read archive header");
		return (0);
	}
	if (ft_memcmp(magic, "!<arch>\n", 8))
		return (0);
	return (1);
}

void	parse_file(t_file *file)
{
	if (parse_file_is_archive(file))
	{
		ft_putendl("Static archive file");
		parse_archive(file);
		return ;
	}
	if (!(buffer_read(&file->buffer, &file->magic, sizeof(file->magic))))
	{
		file_error(file, "Can't read magic number");
		return ;
	}
	buffer_set_position(&file->buffer, 0);
	if (file->magic & MH_OBJECT)
	{
		ft_putendl("Object file");
	}
}
