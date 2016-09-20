/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:06:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 13:59:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		fat_parse_start_arch(t_fat *fat, struct fat_arch fat_arch)
{
	t_fat_file	fat_file;

	fat_file.fat_arch = fat_arch;
	fat_file.object.buffer.data = fat->file->buffer.data + fat_arch.offset;
	fat_file.object.buffer.position = 0;
	fat_file.object.buffer.length = fat_arch.size;
	if (!object_parse(&fat_file.object))
		return (0);
	if (!fat_files_push_back(fat, fat_file))
		return (0);
	return (1);
}

static t_fat	*fat_parse_free(t_fat *fat)
{
	struct_fat_free(fat);
	return (NULL);
}

t_fat			*fat_parse(t_file *file)
{
	t_fat				*fat;
	struct fat_header	fat_header;
	struct fat_arch		fat_arch;
	uint32_t			i;

	if (!buffer_read(&file->buffer, &fat_header, sizeof(fat_header)))
		return (NULL);
	if (!(fat = malloc(sizeof(*fat))))
		return (NULL);
	i = -1;
	fat->files = NULL;
	fat->file = file;
	fat->byte_order = fat_header.magic == FAT_MAGIC ? BO_BIG : BO_LITTLE;
	if (fat->byte_order == BO_LITTLE)
		fat_header_reverse(&fat_header);
	while (++i < fat_header.nfat_arch)
	{
		if (!buffer_read(&file->buffer, &fat_arch, sizeof(fat_arch)))
			return (fat_parse_free(fat));
		if (fat->byte_order == BO_LITTLE)
			fat_arch_reverse(&fat_arch);
		if (!fat_parse_start_arch(fat, fat_arch))
			return (fat_parse_free(fat));
	}
	return (fat);
}
