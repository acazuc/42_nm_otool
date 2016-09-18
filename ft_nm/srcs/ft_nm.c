/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:59:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 10:05:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		start_parse_file(char *name)
{
	t_file			file;
	struct stat		file_stat;

	file.name = name;
	if ((file.fd = open(file.name, O_RDONLY)) == -1)
	{
		file_error(&file, "Failed to open file");
		return ;
	}
	if (fstat(file.fd, &file_stat) == -1)
	{
		close(file.fd);
		file_error(&file, "Failed to read stat from file");
		return ;
	}
	file.buffer.position = 0;
	file.buffer.length = file_stat.st_size;
	if ((file.buffer.data = mmap(NULL, file_stat.st_size
					, PROT_READ | PROT_WRITE
					, MAP_PRIVATE, file.fd, 0)) == MAP_FAILED)
	{
		close(file.fd);
		file_error(&file, "Failed to map file");
		return ;
	}
	parse_file(&file);
}

void			ft_nm(char *file_name, int print_name)
{
	if (print_name)
	{
		ft_putchar('\n');
		ft_putstr(file_name);
		ft_putendl(":");
	}
	start_parse_file(file_name);
}
