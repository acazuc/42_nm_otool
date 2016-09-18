/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_archive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 07:30:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 09:18:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	parse_archive(t_file *file)
{
	t_archive			archive;
	t_ar_file_header	file_header;
	t_ar_file			tmp_file;

	archive.file = file;
	archive.files = NULL;
	while (file->buffer.position != file->buffer.length)
	{
		if (!parse_archive_file_header(file, &file_header))
		{
			file_error(file, "Invalid archive header");
			return ;
		}
		if (!(buffer_read(&file->buffer, tmp_file.name, 20)))
		{
			file_error(file, "Invalid archive file name");
			return ;
		}
		tmp_file.object.buffer.data = file->buffer.data + file->buffer.position;
		tmp_file.object.buffer.position = 0;
		tmp_file.object.buffer.length = ft_atoi(file_header.size) - 20;
		if (!(buffer_read(&file->buffer, tmp_file.object.buffer.data, tmp_file.object.buffer.length)))
		{
			file_error(file, "Invalid archive data");
			return ;
		}
		tmp_file.header = file_header;
		tmp_file.object.file = file;
		archive_files_push_back(&archive.files, tmp_file);
	}
	archive_print(&archive);
}
