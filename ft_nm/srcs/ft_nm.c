/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:59:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/23 10:38:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		error(char *file, char *message)
{
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(message);
}

static void		ft_nm_2(t_file *file)
{
	struct stat	file_stat;

	if (fstat(file->fd, &file_stat) == -1)
	{
		close(file->fd);
		error(file->name, "Failed to read stat from file");
		return ;
	}
	if (!(file->data = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE
					, MAP_ANON | MAP_PRIVATE, -1, 0)))
	{
		close(file->fd);
		error(file->name, "Failed to map file");
		return ;
	}
	parse_file(file);
	print_file(file);
}

void			ft_nm(char *file_name, int print_name)
{
	t_file			file;

	file.name = file_name;
	if (print_name)
	{
		ft_putchar('\n');
		ft_putstr(file.name);
		ft_putendl(":");
	}
	if ((file.fd = open(file.name, O_RDONLY)) == -1)
	{
		error(file.name, "Failed to open file");
		return ;
	}
	ft_nm_2(&file);
}
