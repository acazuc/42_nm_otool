/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:06:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 15:34:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	parse_fat_start_arch(t_fat *fat, struct fat_arch fat_arch)
{
	t_fat_file	fat_file;

	fat_file.fat_arch = fat_arch;
	fat_file.object.buffer.data = fat->file->buffer.data + fat_arch.offset;
	fat_file.object.buffer.position = 0;
	fat_file.object.buffer.length = fat_arch.size;
	if (!parse_object(&fat_file.object))
		return (0);
	if (!fat_files_push_back(fat, fat_file))
		return (0);
	return (1);
}

static int	parse_fat_print_test(t_fat *fat, int32_t arch)
{
	t_fat_file_list	*lst;

	lst = fat->files;
	while (lst)
	{
		if (lst->file.fat_arch.cputype == arch)
		{
			print_object(&lst->file.object);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static void	parse_fat_print(t_fat *fat)
{
	if (parse_fat_print_test(fat, 0x01000007))
		return ;
	if (parse_fat_print_test(fat, 0x01000000))
		return ;
	if (parse_fat_print_test(fat, 0))
		return ;
}

int		parse_fat(t_file *file)
{
	t_fat				fat;
	struct fat_header	fat_header;
	struct fat_arch		fat_arch;
	uint32_t			i;

	if (!buffer_set_position(&file->buffer, 0))
		return (0);
	if (!buffer_read(&file->buffer, &fat_header, sizeof(fat_header)))
		return (0);
	i = 0;
	fat.files = NULL;
	fat.file = file;
	fat.byte_order = fat_header.magic == FAT_MAGIC ? BO_BIG : BO_LITTLE;
	if (fat.byte_order == BO_LITTLE)
		fat_header_reverse(&fat_header);
	while (i < fat_header.nfat_arch)
	{
		if (!buffer_read(&file->buffer, &fat_arch, sizeof(fat_arch)))
			return (0);
		if (fat.byte_order == BO_LITTLE)
			fat_arch_reverse(&fat_arch);
		if (!parse_fat_start_arch(&fat, fat_arch))
			return (0);
		i++;
	}
	parse_fat_print(&fat);
	return (1);
}
