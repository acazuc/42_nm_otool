/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:59:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:50:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		error_open(t_file *file)
{
	char	*str;

	str = "Can't open";
	if (errno == EACCES)
		str = "Permission denied";
	else if (errno == ENOENT)
		str = "File doesn't exists";
	file_error(file, str);
	return (0);
}

static int		open_fstat_s_isdir(t_file *file, struct stat *file_stat)
{
	if ((file->fd = open(file->name, O_RDONLY)) == -1)
		return (error_open(file));
	if (fstat(file->fd, file_stat) == -1)
	{
		close(file->fd);
		file_error(file, "Can't stat");
		return (0);
	}
	if (S_ISDIR(file_stat->st_mode))
	{
		close(file->fd);
		file_error(file, "Is a directory");
		return (0);
	}
	return (1);
}

static void		start_parse_file(char *name, int print_name)
{
	t_file			file;
	struct stat		file_stat;

	file.name = name;
	if (!open_fstat_s_isdir(&file, &file_stat))
		return ;
	file.buffer.position = 0;
	file.buffer.length = file_stat.st_size;
	if ((file.buffer.data = mmap(NULL, file_stat.st_size, PROT_READ
					| PROT_WRITE, MAP_PRIVATE, file.fd, 0)) == MAP_FAILED)
	{
		close(file.fd);
		file_error(&file, "Can't mmap");
		return ;
	}
	parse_file(&file, print_name);
	close(file.fd);
	munmap(file.buffer.data, file_stat.st_size);
}

void			ft_nm(char *file_name, int print_name)
{
	start_parse_file(file_name, print_name);
}
