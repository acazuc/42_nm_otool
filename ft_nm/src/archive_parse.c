/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 07:30:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 15:08:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int			put_file_name(t_ar_file *file, t_file *archive_file)
{
	file->name_length = ft_atoi(file->header.identifier + 3);
	if (!(file->name = malloc(sizeof(*file->name) * file->name_length)))
		return (0);
	if (!(buffer_read(&archive_file->buffer, file->name, file->name_length)))
		return (0);
	return (1);
}

static t_archive	*archive_parse_free(t_archive *archive)
{
	struct_archive_free(archive);
	free(archive);
	return (NULL);
}

static int			archive_parse_set_tmp_file_values(t_ar_file *tmp_file
		, t_file *file, t_ar_file_header file_header)
{
	tmp_file->header = file_header;
	if (!(put_file_name(tmp_file, file)))
		return (0);
	tmp_file->object.buffer.data = file->buffer.data
		+ file->buffer.position;
	tmp_file->object.buffer.position = 0;
	tmp_file->object.buffer.length = ft_atol(file_header.size)
		- tmp_file->name_length;
	return (1);
}

t_archive			*archive_parse(t_env *env, t_file *file)
{
	t_archive			*archive;
	t_ar_file_header	file_header;
	t_ar_file			tmp_file;

	if (!(archive = malloc(sizeof(*archive))))
		return (NULL);
	archive->file = file;
	archive->files = NULL;
	while (file->buffer.position != file->buffer.length)
	{
		if (!archive_parse_file_header(file, &file_header))
			return (archive_parse_free(archive));
		if (!(archive_parse_set_tmp_file_values(&tmp_file, file
						, file_header)))
			return (archive_parse_free(archive));
		if (!(buffer_set_position(&file->buffer, file->buffer.position
						+ tmp_file.object.buffer.length)))
			return (archive_parse_free(archive));
		if (!object_parse(env, &tmp_file.object))
			continue;
		archive_files_push_back(&archive->files, tmp_file);
	}
	return (archive);
}
