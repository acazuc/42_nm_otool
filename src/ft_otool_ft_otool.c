/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:59:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:36:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

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

static void		start_parse_file(t_env *env, char *name, int is_first)
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
	file_parse(env, &file, is_first);
	close(file.fd);
	munmap(file.buffer.data, file_stat.st_size);
}

void			ft_otool(t_env *env, char *file_name, int is_first)
{
	start_parse_file(env, file_name, is_first);
}
