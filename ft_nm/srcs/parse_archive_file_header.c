/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_archive_file_header.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 08:14:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 10:44:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		parse_archive_file_header(t_file *file, t_ar_file_header *file_header)
{
	ft_bzero(file_header->identifier, 17);
	if (!(buffer_read(&file->buffer, file_header->identifier, 16)))
		return (0);
	ft_bzero(file_header->modif_ts, 13);
	if (!(buffer_read(&file->buffer, file_header->modif_ts, 12)))
		return (0);
	ft_bzero(file_header->owner_id, 6);
	if (!(buffer_read(&file->buffer, file_header->owner_id, 6)))
		return (0);
	ft_bzero(file_header->group_id, 6);
	if (!(buffer_read(&file->buffer, file_header->group_id, 6)))
		return (0);
	ft_bzero(file_header->mode, 9);
	if (!(buffer_read(&file->buffer, file_header->mode, 8)))
		return (0);
	ft_bzero(file_header->size, 11);
	if (!(buffer_read(&file->buffer, file_header->size, 10)))
		return (0);
	ft_bzero(file_header->end, 3);
	if (!(buffer_read(&file->buffer, file_header->end, 2)))
		return (0);
	if (ft_strcmp(file_header->end, "`\n"))
		return (0);
	return (1);
}
